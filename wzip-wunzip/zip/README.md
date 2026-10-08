<!--WZIP == zip command implementation-->

### COMMANDS USED:
- fopen(pathname, mode) => opening the file
	- pathname => file wanting to open path
	- mode => read(r), write(w) etc.
	- RETURNS => FILE pointer, or NULL if error occurs while opening file
	- for more details:- `man fopen`

- fgetc(stream) => to read the character from the FILE pointer
	- buffer => storing the file info from stream
	- sizeof(buffer) => size(as the name suggests...hehe)
	- stream => the file place to read the data from
	- RETURN => an integer, NULL if error occurs or end-of-file(EOF) occurs
	- for more details:- `man fgetc`

- fwrite(pointer, size(), size(), stream) => binary stream output
	- pointer => which pointer to look for to store
	- size() => size of each element
	- size() => total size in that list
	- stream => the place to write the data to
	- RETURNS => the number of items written
	- for more details:- `man fwrite`

- fclose(fp) => to close the opened file(flushing the stream)
	- fp => file pointer, returned using fopen()
	- uses fflush() under the hooD
	- RETURN => 0 success, EOF or errno for error
	- for more details:- `man fclose`

## TO RUN THE CODE:
- `gcc -o wzip wzip.c -Wall -Werror`
- `./wzip [file] > [custom_name for file after zip]`
	- `> is a readirection of the output to custom_name file instead of printing to the terminal(stdout)`
