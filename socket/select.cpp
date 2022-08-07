#include <cstdio>
#include <cstdlib>
#include <sys/select.h>
#include <unistd.h>

// https://man7.org/linux/man-pages/man2/select.2.html#:~:text=the%20system%20call.-,EXAMPLES,-top

int main() {
    fd_set read_fds;
    size_t buf_size = 1024;
    char *buf = static_cast<char *>(malloc(buf_size));
    while (true) {
        struct timeval tv{};
        /* Wait up to five seconds. */
        tv.tv_sec = 5;
        tv.tv_usec = 0;

        /* Watch stdin (fd 0) to see when it has input. */
        FD_ZERO(&read_fds);
        FD_SET(0, &read_fds);

        int n = select(1, &read_fds, nullptr, nullptr, &tv);
        /* Don't rely on the value of tv now! */
        // Looks like tv_sec is set to remain seconds
        if (n == -1) {
            perror("select()");
        } else if (n) {
            /* FD_ISSET(0, &read_fds) will be true. */
            printf("Data is available now. FD_ISSET(0, &read_fds) is %d\n", FD_ISSET(0, &read_fds));
            int ret = read(0, buf, buf_size - 1);
            buf[ret] = '\0';
            printf("read: %s\n", buf);
        } else {
            printf("No data within five seconds.\n");
        }
    }
}