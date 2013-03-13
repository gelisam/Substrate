Substrate
===

I often write Makefile scripts which produce lots of intermediate files with anonymous name such as list1, list2, etc. I've been dreaming for a while about a graphical variant of Make which would allow me to omit the filename for my intermediate steps, and would allow me instead to structure my text- and filesystem-manipulations as a graph of the dependencies.

One day, I sat down and decided I would stop dreaming and start implementing! At the time, I was learning Agile at the office so I used this as an experiment for a one-person Agile-team. I gave up after a few iterations, but the iterations I did complete were full of discoveries which you can read on my blog starting from [this post](http://gelisam.blogspot.ca/2012/02/may-day-i-actually-complete-something.html).

This project is currently on hold, but I still need something like that, so I'm probably going to continue working on it someday. Although, knowing myself, I will probably start from scratch instead of continuing the work of this repository.

As it stands, the project is mostly useful because of its file-tracking abilities: put some files in its subfolders, and it will run the UI's bash script every time one of those files changes. If you find that useful but would prefer a command-line interface, check out [Permamake](http://www.scvalex.net/posts/4/)! (also available on github [here](https://github.com/scvalex/script-fu/blob/master/permamake.sh))
