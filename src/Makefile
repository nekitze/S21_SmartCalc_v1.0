CC=gcc
PKGCONFIG = $(shell which pkg-config) 
CFLAGS=-Wall -Wextra -Werror $(shell $(PKGCONFIG) --cflags gtk4) #-fsanitize=address
SOURCES=calc_functions/*
TEST_SOURCES=calc_functions/* tests/*.c tests/*.h tests/suites/*.c
UNAME_S=$(shell uname -s)
GCOV_FLAGS=

ifeq ($(UNAME_S),Linux)
LDFLAGS= -lm -lcheck -lpthread -lsubunit
endif
ifeq ($(UNAME_S),Darwin)
LDFLAGS= -lm -lcheck -lpthread
endif

all: install

test:
	$(CC) $(CFLAGS) $(TEST_SOURCES) $(LDFLAGS) $(GCOV_FLAGS) -o test

gcov_report: GCOV_FLAGS += -fprofile-arcs -ftest-coverage
gcov_report: test
	./test > /dev/null
	lcov --exclude *calc_functions.c -t "report" -o report.info -c -d .
	genhtml -o "html_report" report.info
	open html_report/index.html

install:
	rm -rf s21_smart_calc
	mkdir s21_smart_calc
	qmake qt/qt_smart_calc/qt_smart_calc.pro -o s21_smart_calc
	cd s21_smart_calc && make && cd ../
	chmod +x s21_smart_calc/qt_smart_calc.app
	ln -s ${PWD}/s21_smart_calc/qt_smart_calc.app ${HOME}/Desktop/Smart\ Calc\ v1.0

uninstall:
	rm -rf s21_smart_calc
	rm ${HOME}/Desktop/Smart\ Calc\ v1.0

dvi:
	open README.html

dist: install
	tar -czf s21_smart_calc.tar.gz --directory=s21_smart_calc/ .

style:
	clang-format -style=google -i calc_functions/*.c calc_functions/*.h
	clang-format -style=google -i qt/qt_smart_calc/*.h qt/qt_smart_calc/*.cpp
	clang-format -style=google -n calc_functions/*.c calc_functions/*.h
	clang-format -style=google -n qt/qt_smart_calc/*.h qt/qt_smart_calc/*.cpp

clean:
	rm -rf obj *.a test html_report report.info program *.o *.gch calc_functions/*.gch *.gcno *.gcda s21_smart_calc.tar.gz
	
lib:
	$(CC) -c $(SOURCES) $(LDFLAGS)
	ar -rc libcalc.a *.o
	ranlib libcalc.a

.PHONY: all test clean lib gcov_report
