"""
Validate that all .h files have '#pragma once', and .cpp files dont

Exit codes:
  0 = all checks passed
  1 = one or more violations OR an unreadable file
"""

import pathlib

def check_header(path: pathlib.Path):
    print(f"Checking {path}")
    text = path.read_text(encoding="utf-8")
    assert("#pragma once" in text)

def check_cpp(path: pathlib.Path):
    print(f"Checking {path}")
    text = path.read_text(encoding="utf-8")
    assert("#pragma once" not in text)

if __name__ == "__main__":
    root = pathlib.Path(".")
    for path in root.rglob("*"):
        if not path.is_file():
            continue
        if path.suffix == ".h":
            check_header(path)
        if path.suffix == ".cpp":
            check_cpp(path)

    print("Test passed")