void loop()
{
    printValuesBME280(); // send data to the rainmaker app
    delay(20000); // 20 second interval so it wont run out of budget 
}

