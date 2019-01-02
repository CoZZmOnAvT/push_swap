/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: phrytsenko                                                           */
/*                                                                            */
/*   Created: 2019/01/02 16:17:55 by phrytsenko                               */
/*   Updated: 2019/01/02 16:25:27 by phrytsenko                               */
/*                                                                            */
/* ************************************************************************** */

#include <unity.h>

// void test_GetDataFromHost(void)
// {
//     int sockfd;
//     ntp_packet_t data;
//     struct timeval corrTime;

//     TEST_ASSERT_MESSAGE((sockfd = EstablishConnection(NTP_SERVER_HOSTNAME, NTP_SERVER_PORT)) != -1,
//                         "Couldn't connect to ntp server");
//     TEST_ASSERT(GetDataFromHost(sockfd, NULL, NULL) == -1);
//     TEST_ASSERT(GetDataFromHost(sockfd, &data, NULL) == -1);
//     TEST_ASSERT(GetDataFromHost(sockfd, NULL, &corrTime) == -1);
//     TEST_ASSERT(GetDataFromHost(-1, NULL, NULL) == -1);
//     TEST_ASSERT(GetDataFromHost(-1, &data, NULL) == -1);
//     TEST_ASSERT(GetDataFromHost(-1, NULL, &corrTime) == -1);
//     TEST_ASSERT_MESSAGE(GetDataFromHost(sockfd, &data, &corrTime) != -1, "Couldn't get data from ntp server");
//     close(sockfd);
// }


int main(void)
{
    UNITY_BEGIN();

    // RUN_TEST(test_GetDataFromHost);
    return (UNITY_END());
}
