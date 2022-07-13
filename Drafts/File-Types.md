- File Types:
    - [BIG](#big)
    - [INF](#inf)
    - [DAT](#dat)
    - [MPC](#mpc)


<br>

***

<br>


<!-- Duplicated, should I remove? -->
# BIG
### Overview
EA's archive file.

### Magic signatures
|    Hex   |   ASCII  |
|----------|----------|
| C0FB     | Àû       |
| 42494734 | BIG4     |
| 42494746 | BIGF     |

<br>

# INF
Plain text setup information file.
Used mostly for audio configuration.

# DAT

Data file
Used for Button mappings.

# MPC

<!-- link mpeg ES documentation probs -->

MPC is a EA custom RIFF-based wrapper over a MPEG-1 Elementary Stream.

Often paired with/interleaved with ASF chunks, to provide audio.

# ASF

EA audio stream file. Contains SC* chunks.

