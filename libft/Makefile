# **************************************************************************** #
#                                                                              #
#                                                                              #
#    Makefile                                                                  #
#                                                                              #
#    By: cozzmonavt                                                            #
#                                                                              #
#    Created: 2019/01/05 14:53:53 by cozzmonavt                                #
#    Updated: 2019/01/05 15:17:48 by cozzmonavt                                #
#                                                                              #
# **************************************************************************** #

CC = gcc
DEFAULT_INTERPREU = /bin/bash
BUILD_DIR = ./build

all: ${BUILD_DIR}
	@+${DEFAULT_INTERPREU} -c \
		"cd ${BUILD_DIR} && \
		make -s";

${BUILD_DIR}:
	@${DEFAULT_INTERPREU} -c \
		"mkdir -p ${BUILD_DIR} && \
		cd ${BUILD_DIR} && \
		CC=${CC} cmake ..";

clean:
	@${DEFAULT_INTERPREU} -c \
		"cd ${BUILD_DIR} && \
		find . -name \"*.o\" -delete";

fclean:
	@+${DEFAULT_INTERPREU} -c \
		"cd ${BUILD_DIR} && \
		make -s clean";

re: fclean all
