all: project add compile

project:
	@cd ~ && if [ ! -d public_html ]; then mkdir public_html; fi ;
	@cp binary_converter.c index.html ./public_html/
	@chmod 755 public_html/
	@cd public_html ; \
		chmod 755 index.html;
add:
	@cd public_html/ ; \
		if [ ! -d .git ]; then git init ; fi ;\
		if [ -n "`git status --porcelain | grep -v "cgi-bin"`" ]; then git add binary_converter.c index.html && git commit -m "A program that converts decimal numbers to binary through a browser" ; fi ;
compile:
	@cd ./public_html/ ;\
		gcc -o binary_converter.cgi binary_converter.c ;\
		chmod 755 binary_converter.cgi ;\
		if [ ! -d cgi-bin ]; then mkdir cgi-bin; fi ;\
		chmod 755 cgi-bin/ ;\
		mv binary_converter.cgi cgi-bin/ ;
