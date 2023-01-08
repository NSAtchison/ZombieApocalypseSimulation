// #include "simulator.h"
// #include "gtest\gtest.h"
// #include <vector>
// #include <map>
// #include <iostream>

// //Test a successful zombie bite against an alert person
// TEST(ZombieBiteTests, SuccessfulAlertBite) {
//     Location University;
//     Zombie testZombie(3, 0, 100, 0);//Create a zombie with a 100% chance of biting an unalert person
//     Person* testAlert = new AlertPerson(3, 0, 100, 0);//create an alert person to test against
//     University.addPerson(testAlert);
//     testZombie.action(testAlert, University);
//     EXPECT_EQ((*testAlert).getStatus(), 0);//after a successful bite, the alert person should be a zombie (status should be zero)
// }
// //test a failed zombie bite against an alert person
// TEST(ZombieBiteTests, UnSuccessfulAlertBite) {
//     Location University;
//     Zombie testZombie(3, 100, 0, 100);//Create a zombie with a 0% chance of a successful bite
//     Person* testAlert = new AlertPerson(3, 100, 0, 100);//create an alert person to test against
//     University.addPerson(testAlert);
//     testZombie.action(testAlert, University);
//     EXPECT_EQ((*testAlert).getStatus(), 1);//after an unsuccessful bite, the alert person should be the same (status should be one)
// }
// //test a successful bite against an unalert person
// TEST(ZombieBiteTests, SuccessfulUnalertBite) {
//     Location University;
//     Zombie testZombie(3, 100, 0, 0);//create a zombie with a 100% chance of biting an unalert person
//     Person* testAlert = new UnalertPerson(3, 100, 0, 0);//create an unalert person to test against
//     University.addPerson(testAlert);
//     testZombie.action(testAlert, University);
//     EXPECT_EQ((*testAlert).getStatus(), 0);//after a successful bite, the unalert person should be a zombie (status should be zero)
// }
// //test a failed bite against an unalert person
// TEST(ZombieBiteTests, UnsuccessfulUnalertBite) {
//     Location University;
//     Zombie testZombie(3, 0, 100, 100);//create a zombie with a 0% chance of biting an unalert person
//     Person* testAlert = new UnalertPerson(3, 0, 100, 100);//create an unalert person to test against
//     University.addPerson(testAlert);
//     testZombie.action(testAlert, University);
//     EXPECT_EQ((*testAlert).getStatus(), 1);//after an unsuccessful bite, the unalert person should be an alert person (status should be 1)
// }
// //test an alert person successfully convinces an unalert person
// TEST(AlertConvinceTests, SuccessfulConvice) {
//     Location University;
//     AlertPerson testAlertPerson(3, 0, 0, 100);//create an alert person with a 100% chance of convincing an alert person
//     Person* testUnalert = new UnalertPerson(3, 0, 0, 100);//create an unalert person to test against
//     University.addPerson(testUnalert);
//     testAlertPerson.action(testUnalert, University);
//     EXPECT_EQ((*testUnalert).getStatus(), 1);//after a success, the unalert person should be an alert person (status should be 1)
// }
// //test an alert person failing to convince an unalert person
// TEST(AlertConvinceTests, UnsuccessfulConvice) {
//     Location University;
//     AlertPerson testAlertPerson(3, 100, 100, 0);//create an alert person with a 0% chance of convincing an alert person
//     Person* testUnalert = new UnalertPerson(3, 100, 100, 0);//create an unalert person to test against
//     University.addPerson(testUnalert);
//     testAlertPerson.action(testUnalert, University);
//     EXPECT_EQ((*testUnalert).getStatus(), 2);//after a failure, the unalert person should be the same (status should be 2)
// }





// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
