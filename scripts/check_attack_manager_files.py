"""
Validate that any file named Attack_<digits>_Manager.(cpp|h)
contains the substring 'Attack_<digits>_Manager' in its contents.

Exit codes:
  0 = all checks passed
  1 = one or more violations OR an unreadable file
"""

import pathlib
import re

DEFAULT_FILENAME_RE = re.compile(r"^(Attack_(\d+)_Manager)\.(cpp|h)$")

def find_files(root: pathlib.Path):
    for path in root.rglob("*"):
        if path.is_file() and DEFAULT_FILENAME_RE.match(path.name):
            yield path

def check_file(path: pathlib.Path):
    print(f"Checking {path}")
    required = DEFAULT_FILENAME_RE.match(path.name).group(1)
    text = path.read_text(encoding="utf-8", errors="replace")
    assert(required in text)

def main():
    root = pathlib.Path(".")
    for p in find_files(root):
        check_file(p)

    print("Test passed")

if __name__ == "__main__":
    main()