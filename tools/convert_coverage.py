import argparse
from pathlib import Path
import subprocess
from typing import Sequence


def get_coverage_exe_path() -> Path:
    """
    Get the codecoverage.exe

    Returns:
        (Path) The path to the codecoverage.exe
    """
    base_path = Path("C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Enterprise")
    return next(base_path.glob("**/codecoverage.exe"))


def find_coverage_files(src_path: Path) -> Sequence:
    """
    Find the coverage files within the specified src_path.

    Parameters:
        src_path (Path): The path in which to look for the .coverage files.
    
    Returns:
        (Sequence) The set of .coverage files within the specified folder.
    """
    return src_path.glob("**/*.coverage")


def convert_coverage_to_xml(code_coverage_exe: Path,
                            coverage_path: Path, 
                            output_folder: Path) -> None:
    """
    Convert the specified coverage_path to xml, and return the newly 
    generated Path.

    Parameters:
        coverage_path (Path): .coverage file to convert
        output_path (Path): Path to the output .xml file to create. 
    """
    output_file_path = output_folder / (coverage_path.with_suffix(".xml")).name
    coverage_convert_cmd = "'{}' analyze /output:'{}' '{}'".format(str(code_coverage_exe),
                                                                   str(output_file_path), 
                                                                   str(coverage_path))

    p = subprocess.run(coverage_convert_cmd, shell=True)


def run(coverage_dir: Path, output_folder=None) -> None:
    """
    Convert the .coverage files within coverage_dir to .xml files.

    Parameters:
        coverage_dir (Path): the root directory in which to find the .coverage
                             files.
        output_folder (Path): The output folder to which to export the .xml files.

    Remarks:
        If no output_folder is provided, the .xml files are generated within the
        parent directory of the .coverage files.
    """
    code_coverage_exe = get_coverage_exe_path()

    for coverage_file in find_coverage_files(coverage_dir):
        convert_coverage_to_xml(code_coverage_exe, 
                                coverage_file, 
                                output_folder)


def parse_arguments():
    """
    Parse the arguments provided to this script.
    """
    parser = argparse.ArgumentParser("Convert .coverage to .xml.")

    parser.add_argument("coverage_folder", help="The folder containing the coverage files.")
    parser.add_argument("output_folder", help="The folder to which to export the coverage files.")

    return parser.parse_args()


if __name__ == "__main__":
    args = parse_arguments()

    coverage_dir = Path(args.coverage_folder)
    output_dir = Path(args.output_folder)

    run(coverage_dir, 
        output_dir)