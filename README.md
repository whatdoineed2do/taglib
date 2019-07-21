# TagLib

from [taglib/taglib](https://github.com/taglib/taglib)


This is the [whatdoineed2do](https://github/com/whatdoineed2d/taglib) fork of the [taglib 1.11.1 upstream master](https://github.com/taglib/taglib)

This repo contains these fixes of interest that are pending merge into upstream
* mp4 `set{Track,Year}()` bug fix clearing values (https://github.com/taglib/taglib/pull/912)
* long standing mp3 stripping bug (https://github.com/taglib/taglib/pull/914)

---

[![Build Status](https://travis-ci.org/taglib/taglib.svg?branch=master)](https://travis-ci.org/taglib/taglib)

### TagLib Audio Metadata Library

http://taglib.org/

TagLib is a library for reading and editing the metadata of several
popular audio formats. Currently it supports both ID3v1 and [ID3v2][]
for MP3 files, [Ogg Vorbis][] comments and ID3 tags 
in [FLAC][], MPC, Speex, WavPack, TrueAudio, WAV, AIFF, MP4, APE,
DSF, DFF, and ASF files.

TagLib is distributed under the [GNU Lesser General Public License][]
(LGPL) and [Mozilla Public License][] (MPL). Essentially that means that
it may be used in proprietary applications, but if changes are made to
TagLib they must be contributed back to the project. Please review the
licenses if you are considering using TagLib in your project.

  [ID3v2]: http://www.id3.org 
  [Ogg Vorbis]: http://vorbis.com/
  [FLAC]: https://xiph.org/flac/
  [GNU Lesser General Public License]: http://www.gnu.org/licenses/lgpl.html
  [Mozilla Public License]: http://www.mozilla.org/MPL/MPL-1.1.html

