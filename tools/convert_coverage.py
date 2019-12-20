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
    return Path(".").glob("**/*.coverage")


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
    output_file_path = output_folder / (coverage_path.with_suffix(".coveragexml")).name

    print("output file path: {}".format(str(output_file_path)))

    coverage_convert_cmd = "'{}' analyze /output:{} {}".format(str(code_coverage_exe),
                                                                   str(output_file_path), 
                                                                   str(coverage_path))
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


def run(coverage_dir: Path, output_dir: Path) -> None:
    """
    Convert the .coverage files within coverage_dir to .xml files.

    Parameters:
        coverage_dir (Path): the root directory in which to find the .coverage
                             files.
        output_dir (Path): The output folder to which to export the .xml files.
    """
    print(str(coverage_dir))
    print(str(output_dir))

    if (not (output_dir.exists() and output_dir.is_dir())):
        output_dir.mkdir(parents=True)

    code_coverage_exe = get_coverage_exe_path()
    print(str(code_coverage_exe))

    coverage_file = next(find_coverage_files(coverage_dir))
    convert_coverage_to_xml(code_coverage_exe, 
                            coverage_file, 
                            output_dir)


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
