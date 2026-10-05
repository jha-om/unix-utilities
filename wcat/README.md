<!--WCAT == cat command implementation-->

### COMMANDS USED:
- fopen(pathname, mode) => opening the file
	- pathname => file wanting to open path
	- mode => read(r), write(w) etc.
	- RETURNS => FILE pointer, or NULL if error occurs while opening file
	- for more details:- `man fopen`

- fgets(buffer, sizeof(buffer), stream) => to read the data from the FILE pointer and storing it into buffer
	- buffer => storing the file info from stream
	- sizeof(buffer) => size(as the name suggests...hehe)
	- stream => the file place to read the data from
	- RETURN => pointer to buffer, NULL if error occurs or end-of-file(EOF) occurs
	- for more details:- `man fgets`

- fclose(fp) => to close the opened file(flushing the stream)
	- fp => file pointer, returned using fopen()
	- uses fflush() under the hooD
	- RETURN => 0 success, EOF or errno for error
	- for more details:- `man fclose`

## TO RUN THE CODE:
- `gcc -o wcat wcat.c -Wall -Werror`
