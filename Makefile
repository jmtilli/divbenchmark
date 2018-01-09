.PHONE: all unit

all: div divfast select

div: div.c
	cc -O3 -o div div.c
divfast: divfast.c
	cc -O3 -o divfast divfast.c
select: select.c
	cc -O3 -o select select.c

unit:
	@echo div
	@sh -c "time ./div"
	@echo divfast
	@sh -c "time ./divfast"
	@echo select
	@sh -c "time ./select"
