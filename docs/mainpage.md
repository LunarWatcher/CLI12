# Introduction {#mainpage}

This is the Doxygen API documentation for CLI12 parser. There is a friendly
introduction to CLI12 on the [GitHub page](https://github.com/CLIUtils/CLI11),
and [a tutorial series](https://cliutils.github.io/CLI12/book/).

The main classes are:

| Name           | Where used                                                |
| -------------- | --------------------------------------------------------- |
| CLI::Option    | Options, stored in the app                                |
| CLI::App       | The main application or subcommands                       |
| CLI::Validator | A check that can affect the type name                     |
| CLI::Formatter | A subclassable formatter for help printing                |
| CLI::ExitCode  | A scoped enum with exit codes                             |
| CLI::Timer     | A timer class, only in CLI/Timer.hpp (not in `CLI12.hpp`) |
| CLI::AutoTimer | A timer that prints on deletion                           |

Groups of related topics:

| Name                 | Description                                    |
| -------------------- | ---------------------------------------------- |
| @ref error_group     | Errors that can be thrown                      |
| @ref validator_group | Common validators used in CLI::Option::check() |
