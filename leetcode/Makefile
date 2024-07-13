.PHONY: format format-cpp format-go format-kt format-py

format: format-cpp format-go format-kt format-py

format-cpp:
	clang-format-9 -i *.cpp *.java

format-go:
	gofmt -w *.go

format-kt:
	ktfmt *.kt

format-py:
	autopep8 -i *.py
