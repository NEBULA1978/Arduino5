#include "AsyncTaskLib.h"

AsyncTask asyncTask1(1000, []() { digitalWrite(LED_BUILTIN, HIGH); });
AsyncTask asyncTask2(2000, []() { digitalWrite(LED_BUILTIN, LOW); });

void setup()
{
   pinMode(LED_BUILTIN, OUTPUT);

   asyncTask1.Start();
}

void loop()
{
   asyncTask1.Update(asyncTask2);
   asyncTask2.Update(asyncTask1);
}
