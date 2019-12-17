from pathlib import Path
import argparse


RUNSETTINGS_TEMPLATE = """<?xml version="1.0" encoding="UTF-8"?>
<RunSettings>
  <RunConfiguration>
    <ResultsDirectory>{}</ResultsDirectory>
  </RunConfiguration>
</RunSettings>
"""

def generate_runsettings(runsettings_path: Path, results_dir: Path) -> None:
    """
    Generate a runsettings file specifying the ResultsDirectory results_dir
    aat the runsettings_path location.

    Parameters:
        runsettings_path (Path): Path to where the file will be generated.
        results_dir (Path): Path to the directory where the output will be directed to.
    """
    runsettings_content = RUNSETTINGS_TEMPLATE.format(str(results_dir))

    with runsettings_path.open(mode='w') as f:
        f.write(runsettings_content)


def run(runsettings_path: Path, results_dir: Path) -> None:
    """
    Generate a runsettings file at the specified path.
    Generate the directory in which the results will be generated.

    Parameters:
        runsettings_path (Path): Path to where the file will be generated.
        results_dir (Path): Path to the directory where the output will be directed to.
    """
    if not results_dir.exists() or not results_dir.is_dir():
        results_dir.mkdir(parents=True)

    runsettings_dir = runsettings_path.parent
    if not runsettings_dir.exists() or not runsettings_dir.is_dir():
        runsettings_dir.mkdir(parents=True)

    generate_runsettings(runsettings_path, results_dir)


def parse_arguments():
    """
    Parse the arguments provided to this script.
    """
    parser = argparse.ArgumentParser("Convert .coverage to .xml.")

    parser.add_argument("runsettings_path", help="Path to the runsettings file that will be generated.")
    parser.add_argument("results_dir", help="Path to the directory in which results will be generated.")

    return parser.parse_args()


if __name__ == "__main__":
    args = parse_arguments()

    runsettings_path = Path(args.runsettings_path)
    results_dir = Path(args.results_dir)

    run(runsettings_path, 
        results_dir)
