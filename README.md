# Nested_m3u_playlist_tool

This is a simple mini project that I have started to build to handle nested multimedia playlists within other multimedia playlists.

Some time ago I decided to make my personal audio playlists more modular.
It became difficult to edit large playlists with hundreds of files in one single playlist.
I experimented with trying nested m3u files within other m3u files.
Using a text editor I tried to enter into a master .m3u playlist a bunch of other smaller playlists.
To my surprise these could actually be loaded into VLC Media Player!
However, I was faced with a new challenge - being able to edit the new playlists and still be able to maintain the modular structure.
Say, for example, I wanted to mix and match playlists while I worked, or played computer games... perhaps I wanted to play Minecraft on my PC but listen to my favourite tracks from other computer games?
Perhaps one day I wanted to listen to Age of Empires II and A Hat in Time, but the next I wanted to listen to a few Role Playing Game favourites?
Or, perhaps I wanted to listen to Tetris and Puyo Puyo, but change my Tetris and Puyo Puyo playlists individually?
In each of these cases I wanted to select both the original game and the audio tracks from within that original game.
Maybe I wanted to listen to hardcore boss battle music while chopping trees, or a calm fanfare while swarmed with enemies?

The aim of this tool is to be able to support handling multiple tiers of playlist so that editing it does not lead to any subplaylists being forgotten in the process.

Here is an example structure, where Playlist A is a master playlist and B, C and D are subplaylists:

- Playlist A
  - Playlist B
  - Playlist C
  - Playlist D

- Playlist B
  - Track B1
  - Track B2
  - Track B3
- Playlist C
  - Track C1
  - Track C2
- Playlist D
  - Track D1
  - Track D2
  - Track D3
  
In VLC [insert version number!], I found that opening nested playlists is supported, but the integrity of the nested structure was lost.
Using the above example, I have found the following happens if opening Playlist B from within Playlist A:

Playlist A
  - Track B1
  - Track B2
  - Track B3
  - Playlist C
  - Playlist D
  
Now we can access Playlist B's tracks, but the playlist loaded into RAM does not remember where they came from.
To work around this, using a tree structure overcomes this issue:

- Playlist A
  - Playlist B
    - Track B1
    - Track B2
    - Track B3
  - Playlist C
    - Track C1
    - Track C2
  - Playlist D
    - Track D1
    - Track D2
    - Track D3

This program remains a work in progress and I have attempted to rewrite this multiple times over the years.
Perhaps one day I may actually build enough of it to be satisfied?
We'll wait and see for now...

Note that this program was developed using an IDE, namely Code::Blocks.
To run, clone the repository, open the project in Code::Blocks, Build and run the program.
