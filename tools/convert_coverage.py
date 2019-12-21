import argparse
from pathlib import Path
import subprocess
from typing import Sequence
import shutil


def find_coverage_files(src_path: Path) -> Sequence:
    """
    Find the coverage files within the specified src_path.

    Parameters:
        src_path (Path): The path in which to look for the .coverage files.
    
    Returns:
        (Sequence) The set of .coverage files within the specified folder.
    """
    return Path(src_path).glob("**/*.coverage")


def copy_coverage_files_to_cwd(coverage_files: Sequence) -> None:
    """
    Copy the Sequence of coverage files to the current working 
    directory as coverage_<n>.coverage.

    Parameters:
        coverage_files (Sequence): Sequence of Paths to copy to the working directory
    """
    i = 0
    new_coverage_name_template = "coverage_{}.coverage"

    for cov_path in coverage_files:
        new_name = new_coverage_name_template.format(i)
        goal_path = Path(new_name)

        shutil.move(str(cov_path), str(goal_path))

        i += 1


def convert_coverage_to_xml(code_coverage_exe: Path,
                            coverage_path: Path) -> None:
    """
    Convert the specified coverage_path to xml, and return the newly 
    generated Path.

    Parameters:
        coverage_path (Path): .coverage file to convert located in the current folder
        output_path (Path): Path to the output .xml file to create. 

    Remarks:
        If a coverage_path is provided other than the current working directory,
        the behaviour is undefined.
    """
    output_file_path = coverage_path.with_suffix(".xml")
    coverage_convert_cmd = "{} analyze /output:{} {}".format(str(code_coverage_exe),
                                                             output_file_path.name, 
                                                             coverage_path.name)
    print("coverage path:\n  {}".format(coverage_convert_cmd))

    encoding = "utf-8"
    p = subprocess.run(coverage_convert_cmd, 
                       shell=True, 
                       encoding=encoding,
                       stdout=subprocess.PIPE,
                       stderr=subprocess.PIPE)

    print("stdout:")
    print("{}\n".format(str(p.stdout)))

    print("stderr:")
    print("{}\n".format(str(p.stderr)))


def run(coverage_exe: Path, coverage_dir: Path) -> None:
    """
    Convert the .coverage files within coverage_dir to .xml files.

    Parameters:
        coverage_dir (Path): the root directory in which to find the .coverage
                             files.
    """
    print(str(coverage_dir))
    src_coverage_files = find_coverage_files(coverage_dir)
    copy_coverage_files_to_cwd(src_coverage_files)

    cwd_coverage_files = find_coverage_files(".")

    for coverage_path in cwd_coverage_files:
        convert_coverage_to_xml(coverage_exe, 
                                coverage_path)


def parse_arguments():
    """
    Parse the arguments provided to this script.
    """
    parser = argparse.ArgumentParser("Convert .coverage to .xml.")
    parser.add_argument("coverage_exe", help="The path to the coverage executable.")
    parser.add_argument("coverage_folder", help="The folder containing the coverage files.")
    return parser.parse_args()


if __name__ == "__main__":
    args = parse_arguments()

    coverage_exe = Path(args.coverage_exe)
    coverage_dir = Path(args.coverage_folder)
    run(coverage_exe, coverage_dir)
