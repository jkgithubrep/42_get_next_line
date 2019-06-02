# Get_next_line

The __*get_next_line*__ project at [42](https://www.42.fr/) consists in coding a function that reads a line ended by a newline from a given file descriptor.

## Mandatory part

A *line* is a sequence of characters ended by the ascii character `\n` or by `End Of File (EOF)`.

The function must have the following prototype:
```
int		get_next_line(const int fd, char **line)
```

It stores the line read in the `line` variable without the `\n` character.

Return values are:
- `1`: a line has been read
- `0`: EOF has been reached
- `-1`: an error occured

Only the following functions from the libc are authorized:
- `read`
- `malloc`
- `free`

Global variables are forbidden.

## Bonus part

As bonuses for this project, my *get_next_line* function includes the following:
- use only 1 static variable
- handle multiple file descriptors alternatively

## Key learnings

First use of a static variable
