# Contributing

Thanks for considering to write a Pull Request (PR) for CLI11! Here are a few
guidelines to get you started:

Make sure you are comfortable with the license; all contributions are licensed
under the original license.

## Adding functionality

Make sure any new functions you add are are:

- Documented by `///` documentation for Doxygen
- Mentioned in the instructions in the README, though brief mentions are okay
- Explained in your PR (or previously explained in an Issue mentioned in the PR)
- Completely covered by tests

In general, make sure the addition is well thought out and does not increase the
complexity of CLI11 needlessly.

## Things you should know

- Once you make the PR, tests will run to make sure your code works on all
  supported platforms
- The test coverage is also measured, and that should remain 100%
- Formatting should be done with pre-commit, otherwise the format check will not
  pass. However, it is trivial to apply this to your PR, so don't worry about
  this check. If you do want to run it, see below.
- Everything must pass clang-tidy as well, run with
  `-DCMAKE_CXX_CLANG_TIDY="$(which clang-tidy)"` (if you set
  `"$(which clang-tidy) -fix"`, make sure you use a single threaded build
  process, or just build one example target).
- Your changes must also conform to most of the
  [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
  rules checked by [cpplint](https://github.com/cpplint/cpplint). For unused
  cpplint filters and justifications, see [CPPLINT.cfg](/CPPLINT.cfg).

## Pre-commit

Format is handled by pre-commit. You should install it (or use
[pipx](https://pypa.github.io/pipx/)):

```bash
python3 -m pip install pre-commit
```

Then, you can run it on the items you've added to your staging area, or all
files:

```bash
pre-commit run
# OR
pre-commit run --all-files
```

And, if you want to always use it, you can install it as a git hook (hence the
name, pre-commit):

```bash
pre-commit install
```

### Use of generative AI is banned

Generative AI uses training data [based on plagiarism and piracy](https://web.archive.org/web/20250000000000*/https://www.theatlantic.com/technology/archive/2025/03/libgen-meta-openai/682093/), has [significant environmental costs associated with it](https://doi.org/10.21428/e4baedd9.9070dfe7), and [generates fundamentally insecure code](https://doi.org/10.1007/s10664-024-10590-1). GenAI is not ethically built, ethical to use, nor safe to use for programming applications. When caught, you will be permanently banned from contributing to the project, and any prior contributions will be checked and potentially reverted. Any and all contributions you've made cannot be trusted if AI slop machines were involved.
