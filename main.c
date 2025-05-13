#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    (void)argc; // Unused parameters
    (void)argv;

    // Test 1: Simple external command (ls -l)
    printf("Test 1: ls -l\n");
    char *ls_args[] = {"ls", "-l", NULL};
    t_cmd ls_cmd = {
        .command = "ls",
        .args = ls_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&ls_cmd, &ls_cmd, envp);

    // Test 2: Command with absolute path (/bin/ls -l)
    printf("\nTest 2: /bin/ls -l\n");
    char *abs_ls_args[] = {"/bin/ls", "-l", NULL};
    t_cmd abs_ls_cmd = {
        .command = "/bin/ls",
        .args = abs_ls_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&abs_ls_cmd, &abs_ls_cmd, envp);

    // Test 3: Command with relative path (./myprogram)
    printf("\nTest 3: ./myprogram\n");
    char *myprogram_args[] = {"./myprogram", NULL};
    t_cmd myprogram_cmd = {
        .command = "./myprogram",
        .args = myprogram_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&myprogram_cmd, &myprogram_cmd, envp);

    // Test 4: Command not found (nonexistentcommand)
    printf("\nTest 4: nonexistentcommand\n");
    char *nonexistent_args[] = {"nonexistentcommand", NULL};
    t_cmd nonexistent_cmd = {
        .command = "nonexistentcommand",
        .args = nonexistent_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&nonexistent_cmd, &nonexistent_cmd, envp);

    // Test 5: Command with arguments (echo Hello, World!)
    printf("\nTest 5: echo Hello, World!\n");
    char *echo_args[] = {"echo", "Hello, World!", NULL};
    t_cmd echo_cmd = {
        .command = "echo",
        .args = echo_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&echo_cmd, &echo_cmd, envp);

    // Test 6: Command with environment variables (env)
    printf("\nTest 6: env\n");
    char *env_args[] = {"env", NULL};
    t_cmd env_cmd = {
        .command = "env",
        .args = env_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&env_cmd, &env_cmd, envp);

    // Test 7: Command with input/output redirection (cat < input.txt > output.txt)
    printf("\nTest 7: cat < input.txt > output.txt\n");
    char *cat_args[] = {"cat", NULL};
    t_cmd cat_cmd = {
        .command = "cat",
        .args = cat_args,
        .input_redirect = "input.txt",
        .output_redirect = "output.txt",
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&cat_cmd, &cat_cmd, envp);

    // Test 8: Command with pipes (ls -l | grep .txt)
    printf("\nTest 8: ls -l | grep .txt\n");
    char *ls_pipe_args[] = {"ls", "-l", NULL};
    t_cmd ls_pipe_cmd = {
        .command = "ls",
        .args = ls_pipe_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 1,
        .next = NULL
    };
    char *grep_pipe_args[] = {"grep", ".txt", NULL};
    t_cmd grep_pipe_cmd = {
        .command = "grep",
        .args = grep_pipe_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    ls_pipe_cmd.next = &grep_pipe_cmd;
    execute_pipeline(&ls_pipe_cmd, &grep_pipe_cmd, envp);

    // Test 9: Built-in command (cd /tmp)
    printf("\nTest 9: cd /tmp\n");
    char *cd_args[] = {"cd", "/tmp", NULL};
    t_cmd cd_cmd = {
        .command = "cd",
        .args = cd_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&cd_cmd, &cd_cmd, envp);

    // Test 10: Command with invalid arguments (ls --invalid-option)
    printf("\nTest 10: ls --invalid-option\n");
    char *invalid_ls_args[] = {"ls", "--invalid-option", NULL};
    t_cmd invalid_ls_cmd = {
        .command = "ls",
        .args = invalid_ls_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&invalid_ls_cmd, &invalid_ls_cmd, envp);

    // Test 11: Command with large output (yes | head -n 1000)
    // printf("\nTest 11: yes | head -n 1000\n");
    // char *yes_args[] = {"yes", NULL};
    // t_cmd yes_cmd = {
    //     .command = "yes",
    //     .args = yes_args,
    //     .input_redirect = NULL,
    //     .output_redirect = NULL,
    //     .is_background = 0,
    //     .is_pipe = 1,
    //     .next = NULL
    // };
    // char *head_args[] = {"head", "-n", "1000", NULL};
    // t_cmd head_cmd = {
    //     .command = "head",
    //     .args = head_args,
    //     .input_redirect = NULL,
    //     .output_redirect = NULL,
    //     .is_background = 0,
    //     .is_pipe = 0,
    //     .next = NULL
    // };
    // yes_cmd.next = &head_cmd;
    // execute_pipeline(&yes_cmd, &head_cmd, envp);

    // Test 12: Command with no output (true)
    printf("\nTest 12: true\n");
    char *true_args[] = {"true", NULL};
    t_cmd true_cmd = {
        .command = "true",
        .args = true_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&true_cmd, &true_cmd, envp);

    // Test 13: Command with error output (ls /nonexistentdirectory)
    printf("\nTest 13: ls /nonexistentdirectory\n");
    char *ls_error_args[] = {"ls", "/nonexistentdirectory", NULL};
    t_cmd ls_error_cmd = {
        .command = "ls",
        .args = ls_error_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&ls_error_cmd, &ls_error_cmd, envp);

    // Test 14: Command with custom environment (env MY_VAR=Hello ./myprogram)
    printf("\nTest 14: env MY_VAR=Hello ./myprogram\n");
    char *env_custom_args[] = {"env", "MY_VAR=Hello", "./myprogram", NULL};
    t_cmd env_custom_cmd = {
        .command = "env",
        .args = env_custom_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&env_custom_cmd, &env_custom_cmd, envp);

    // Test 15: Command with timeout (sleep 5)
    printf("\nTest 15: sleep 5\n");
    char *sleep_args[] = {"sleep", "5", NULL};
    t_cmd sleep_cmd = {
        .command = "sleep",
        .args = sleep_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&sleep_cmd, &sleep_cmd, envp);

    // Test 16: Command with signal handling (sleep 10, interrupt with Ctrl+C)
    printf("\nTest 16: sleep 10 (interrupt with Ctrl+C)\n");
    char *sleep_interrupt_args[] = {"sleep", "10", NULL};
    t_cmd sleep_interrupt_cmd = {
        .command = "sleep",
        .args = sleep_interrupt_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&sleep_interrupt_cmd, &sleep_interrupt_cmd, envp);

    // Test 17: Command with multiple children (ls -l & ls -a &)
    printf("\nTest 17: ls -l & ls -a &\n");
    char *ls_l_args[] = {"ls", "-l", NULL};
    t_cmd ls_l_cmd = {
        .command = "ls",
        .args = ls_l_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 1,
        .is_pipe = 0,
        .next = NULL
    };
    char *ls_a_args[] = {"ls", "-a", NULL};
    t_cmd ls_a_cmd = {
        .command = "ls",
        .args = ls_a_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 1,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&ls_l_cmd, &ls_l_cmd, envp);
    execute_pipeline(&ls_a_cmd, &ls_a_cmd, envp);

    // Test 18: Command with special characters (echo "Hello, $USER!")
    printf("\nTest 18: echo \"Hello, $USER!\"\n");
    char *echo_user_args[] = {"echo", "Hello, $USER!", NULL};
    t_cmd echo_user_cmd = {
        .command = "echo",
        .args = echo_user_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&echo_user_cmd, &echo_user_cmd, envp);

    // Test 19: Command with large input (cat < largefile.txt)
    printf("\nTest 19: cat < largefile.txt\n");
    char *cat_large_args[] = {"cat", NULL};
    t_cmd cat_large_cmd = {
        .command = "cat",
        .args = cat_large_args,
        .input_redirect = "largefile.txt",
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&cat_large_cmd, &cat_large_cmd, envp);

    // Test 20: Command with non-executable file (./non_executable_file)
    printf("\nTest 20: ./non_executable_file\n");
    char *non_exec_args[] = {"./non_executable_file", NULL};
    t_cmd non_exec_cmd = {
        .command = "./non_executable_file",
        .args = non_exec_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0,
        .next = NULL
    };
    execute_pipeline(&non_exec_cmd, &non_exec_cmd, envp);

    return 0;
}