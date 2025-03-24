#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    (void)argc; // Unused parameters
    (void)argv;

    // Hard-code the first command: ls -l
    char *ls_args[] = {"ls", "-l", NULL};
    t_cmd ls_cmd = {
        .command = "ls",
        .args = ls_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 1, // This command is followed by a pipe
        .next = NULL
    };

    // Hard-code the second command: grep .c
    char *grep_args[] = {"grep", ".c", NULL};
    t_cmd grep_cmd = {
        .command = "grep",
        .args = grep_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 1, // This command is followed by a pipe
        .next = NULL
    };

    // Hard-code the third command: wc -l
    char *wc_args[] = {"wc", "-l", NULL};
    t_cmd wc_cmd = {
        .command = "wc",
        .args = wc_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 1, // This command is followed by a pipe
        .next = NULL
    };

    // Hard-code the fourth command: sort -n
    char *sort_args[] = {"sort", "-n", NULL};
    t_cmd sort_cmd = {
        .command = "sort",
        .args = sort_args,
        .input_redirect = NULL,
        .output_redirect = NULL,
        .is_background = 0,
        .is_pipe = 0, // This is the last command in the pipeline
        .next = NULL
    };

    // Link the commands together
    ls_cmd.next = &grep_cmd;
    grep_cmd.next = &wc_cmd;
    wc_cmd.next = &sort_cmd;

    // Execute the pipeline
    execute_pipeline(&ls_cmd, &sort_cmd, envp);

    // Free the command nodes (if dynamically allocated)
    // free_cmd_node(&ls_cmd);    // Uncomment if using dynamic allocation
    // free_cmd_node(&grep_cmd);  // Uncomment if using dynamic allocation
    // free_cmd_node(&wc_cmd);    // Uncomment if using dynamic allocation
    // free_cmd_node(&sort_cmd);  // Uncomment if using dynamic allocation

    return 0;
}