import subprocess
import os
from colorama import Fore, Style, init

# Initialize colorama
init(autoreset=True)

# Path to the minishell executable
MINISHELL_PATH = "./minishell"

def print_success(message):
    """Print a success message in green."""
    print(Fore.GREEN + "[PASS] " + message + Style.RESET_ALL)

def print_failure(message):
    """Print a failure message in red."""
    print(Fore.RED + "[FAIL] " + message + Style.RESET_ALL)

def print_info(message):
    """Print an informational message in blue."""
    print(Fore.BLUE + "[INFO] " + message + Style.RESET_ALL)

def run_minishell_command(command):
    """Run a command in minishell and return the output."""
    process = subprocess.Popen([MINISHELL_PATH], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    stdout, stderr = process.communicate(input=command + "\nexit\n")
    return stdout.strip(), stderr.strip()

def test_cd():
    """Test the 'cd' command."""
    print_info("Testing 'cd' command...")
    
    # Test changing to a valid directory
    test_dir = "/tmp"
    run_minishell_command(f"cd {test_dir}")
    current_dir = os.getcwd()
    if current_dir == test_dir:
        print_success(f"cd to valid directory: {test_dir}")
    else:
        print_failure(f"cd to valid directory: expected {test_dir}, got {current_dir}")
    
    # Test changing to an invalid directory
    invalid_dir = "/nonexistent"
    _, stderr = run_minishell_command(f"cd {invalid_dir}")
    if "No such file or directory" in stderr:
        print_success("cd to invalid directory")
    else:
        print_failure(f"cd to invalid directory: expected error, got {stderr}")

def test_echo():
    """Test the 'echo' command."""
    print_info("Testing 'echo' command...")
    
    # Test simple echo
    output, _ = run_minishell_command("echo Hello, World!")
    if output == "Hello, World!":
        print_success("echo simple string")
    else:
        print_failure(f"echo simple string: expected 'Hello, World!', got '{output}'")
    
    # Test echo with environment variable
    os.environ["TEST_VAR"] = "123"
    output, _ = run_minishell_command("echo $TEST_VAR")
    if output == "123":
        print_success("echo with environment variable")
    else:
        print_failure(f"echo with environment variable: expected '123', got '{output}'")

def test_pwd():
    """Test the 'pwd' command."""
    print_info("Testing 'pwd' command...")
    
    expected_pwd = os.getcwd()
    output, _ = run_minishell_command("pwd")
    if output == expected_pwd:
        print_success("pwd")
    else:
        print_failure(f"pwd: expected '{expected_pwd}', got '{output}'")

def test_export():
    """Test the 'export' command."""
    print_info("Testing 'export' command...")
    
    # Export a new variable
    run_minishell_command("export TEST_VAR=456")
    output, _ = run_minishell_command("echo $TEST_VAR")
    if output == "456":
        print_success("export new variable")
    else:
        print_failure(f"export new variable: expected '456', got '{output}'")
    
    # Export an existing variable
    run_minishell_command("export TEST_VAR=789")
    output, _ = run_minishell_command("echo $TEST_VAR")
    if output == "789":
        print_success("export existing variable")
    else:
        print_failure(f"export existing variable: expected '789', got '{output}'")

def test_unset():
    """Test the 'unset' command."""
    print_info("Testing 'unset' command...")
    
    # Unset an existing variable
    os.environ["TEST_VAR"] = "123"
    run_minishell_command("unset TEST_VAR")
    output, _ = run_minishell_command("echo $TEST_VAR")
    if output == "":
        print_success("unset existing variable")
    else:
        print_failure(f"unset existing variable: expected empty string, got '{output}'")
    
    # Unset a non-existing variable
    run_minishell_command("unset NON_EXISTENT_VAR")
    output, _ = run_minishell_command("echo $NON_EXISTENT_VAR")
    if output == "":
        print_success("unset non-existing variable")
    else:
        print_failure(f"unset non-existing variable: expected empty string, got '{output}'")

def test_env():
    """Test the 'env' command."""
    print_info("Testing 'env' command...")
    
    # Get the current environment
    env_before = dict(os.environ)
    
    # Add a new variable
    os.environ["TEST_VAR"] = "123"
    
    # Run env command
    output, _ = run_minishell_command("env")
    
    # Check if the new variable is in the output
    if "TEST_VAR=123" in output:
        print_success("env with new variable")
    else:
        print_failure("env with new variable: 'TEST_VAR=123' not found in output")
    
    # Restore the environment
    os.environ.clear()
    os.environ.update(env_before)

def test_exit():
    """Test the 'exit' command."""
    print_info("Testing 'exit' command...")
    
    # Test exit with no arguments
    process = subprocess.Popen([MINISHELL_PATH], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    stdout, stderr = process.communicate(input="exit\n")
    if process.returncode == 0:
        print_success("exit with no arguments")
    else:
        print_failure(f"exit with no arguments: expected return code 0, got {process.returncode}")
    
    # Test exit with a specific status code
    process = subprocess.Popen([MINISHELL_PATH], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    stdout, stderr = process.communicate(input="exit 42\n")
    if process.returncode == 42:
        print_success("exit with status code 42")
    else:
        print_failure(f"exit with status code 42: expected return code 42, got {process.returncode}")

def main():
    """Main function to run all tests."""
    test_cd()
    test_echo()
    test_pwd()
    test_export()
    test_unset()
    test_env()
    test_exit()

if __name__ == "__main__":
    main()