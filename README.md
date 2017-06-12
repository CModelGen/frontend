# CModelGen Frontend

This project implements a frontend program for [CModelGen](https://github.com/CModelGen/CModelGen).
The program is extended from the [Icarus Verilog](http://iverilog.icarus.com/).

The source code is open under the [GNU General Public License Version 2](https://www.gnu.org/licenses/old-licenses/gpl-2.0.txt).

## Building the Program

This GIT repository is a submodule of [CModelGen](https://github.com/CModelGen/CModelGen).
When building CModelGen, commands to build this program are automatically invoked.

Alternatively, this program can be built manually.

To build the program, please ensure the following programs are already installed.

- GNU Make
- autoconf
- gperf
- flex
- bison
- readline
- gcc
- g++

The following commands can be used to build the program.

## Using the Program

This program is invoked by CModelGen automatically. To see how it is invoked, add the `--verbose` flag to any CModelGen-invoking command.
