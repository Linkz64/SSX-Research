## RefPack

RefPack is a LZSS-like compression algorithm written by Frank Barchard, and used in many EA file formats.

## Magic

RefPack often manifests itself starting with a magic `0x10FB`.

| Byte    | Meaning        |
|---------|----------------|
| `0x10`  | Flags.         |
| `0xFB`  | Frank Barchard.|

The Uint24 after this magic contains the decompressed size. After this is the LZSS bitstream.

## Bitstream Documentation

Coming Soon!

Quit bugging me!
