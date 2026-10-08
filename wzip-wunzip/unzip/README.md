<!--WUNZIP == unzip command implementation-->

### COMMANDS USED:
- fopen(pathname, mode) => opening the file
	- pathname => file wanting to open path
	- mode => read(r), write(w) etc.
	- RETURNS => FILE pointer, or NULL if error occurs while opening file
	- for more details:- `man fopen`

- fread(pointer, size(), size(), stream) => binary stream input
	- pointer => which pointer to look for to store
	- size() => size of each element
	- size() => total size in that list
	- stream => the place to read the data to
	- RETURNS => the number of items read
	- for more details:- `man fread`

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
- `gcc -o wunzip wunzip.c -Wall -Werror`
- `./wzip [custom_name for file after zip]`
