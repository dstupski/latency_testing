# latency_testing
basic code for testing latency of VB lavb optogenetic LED systems

Works by setting up a rosnode that waits for a trigger command published through the command line 
then measuring the time between recieving that command and a voltage rise on a photodiode

