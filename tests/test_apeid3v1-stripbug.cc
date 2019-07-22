#include <iostream>
#include <taglib/mpegfile.h>

int main(int argc, char *argv[])
{
    if (argc < 3) {
        return 1;
    }
    try
    {
        TagLib::MPEG::File  f(argv[1], false);
        switch (*argv[2])
        {
          case '0':
            std::cout << "ape, id3v1\n";
            // with master, must strip seperately and id3v1 last
            f.strip(TagLib::MPEG::File::APE);
            f.strip(TagLib::MPEG::File::ID3v1);
            break;

          case '1':
            std::cout << "id3v1, ape\n";
            // only removes APE tag if both exist, leaving id3v1!!
            f.strip(TagLib::MPEG::File::ID3v1);
            f.strip(TagLib::MPEG::File::APE);
            break;

          case '2':
            std::cout << "id3v1, ape, true\n";
            f.strip(TagLib::MPEG::File::ID3v1, true); // 
            f.strip(TagLib::MPEG::File::APE, true);   // this will NOT work
            break;

          case '3':
            std::cout << "id3v1, ape, false, true\n";
            f.strip(TagLib::MPEG::File::ID3v1, false); // 
            f.strip(TagLib::MPEG::File::APE, true);   // this will NOT work
            break;

          default:
            // if we have ape/idv1 tags, the first time we call this it only removes the ape
            // if there is only idv1 tag, then the removal is fine
            std::cout << "ape | id3v1\n";
            f.strip(TagLib::MPEG::File::APE | TagLib::MPEG::File::ID3v1);
        }
        f.save(TagLib::MPEG::File::ID3v2);
        //f.save(TagLib::MPEG::File::ID3v2, false, 4, false);
/*
 * using f.save(TagLib::MPEG::File::ID3v2, false, 4, false); also results in the original ID3v1 tag being untouched even it was requested to be stripped.
 */
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}
