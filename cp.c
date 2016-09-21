#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>

struct opt
{
	int append;
};

int cp(const char* infile, const char* outfile)
{
	int ifd = open(infile,O_RDONLY);
	if( ifd == -1)
	{
		printf("error in opening %s", infile);
		return -1;
	}
	int ofd = open(outfile,O_WRONLY | O_CREAT | O_TRUNC);
	if( ofd == -1)
	{
		printf("error in opening %s", outfile);
		return -1;
	}

	int buffer;
	while (read(ifd,&buffer,sizeof(buffer)) != -1)
	{

		if(write(ofd,&buffer,sizeof(buffer)) != - 1)
		{
			printf("error in writing %s", outfile);
			return -1; 
		}
	}
	close(ifd);
	close(ofd);
	return 0;
}


int tee(const char* file, struct opt options )
{
	char buffer;
	while (read(STDIN_FILENO,&buffer,sizeof(buffer) != -1) )
	{
		printf("%c",buffer);
	}
}

int processOpt(int argc,  char const *  argv[], struct opt* options)
{
	int opt;
	while((opt = getopt(argc,argv,":ab:c:d:h:i:j") )!= -1)
	{
		switch(opt)
		{
			case 'a':
				options->append = 1;break;
			default:
				break;
		}
	}
}

int main(int argc, char const *argv[])
{
	struct opt options;
	//processOpt(argc,argv,&options);
	return tee(	argv[1],options);
	//return 0;//cp(argv[1],argv[2]);
}