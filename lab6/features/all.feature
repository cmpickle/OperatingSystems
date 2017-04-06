Feature: Source file must be present, compilable and output correct information

	Scenario: disksked.c must be found
		When I run `rm ../../bin/*`
		Then I run `cp ../../disksked.c ../../bin/`
		Then a file named "../../bin/disksked.c" should exist
		Then 10 points are awarded

	Scenario: disksked.c must be compilable with no errors
		When I run `gcc -std=c99 -o ../../bin/disksked ../../bin/disksked.c` 
		Then a file named "../../bin/disksked" should exist
		Then 10 points are awarded

	Scenario: disksked correctly reports FCFS multiple times
		When I run `disksked` randomly 
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		Then the stdout should contain the correct FCFS report
		When I run `disksked` randomly 
		Then the stdout should contain the correct FCFS report
		Then 20 points are awarded

	Scenario: disksked correctly reports SSTF multiple times
		When I run `disksked` randomly 
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SSTF report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SSTF report
		Then 20 points are awarded

	Scenario: disksked correctly reports SCAN multiple times
		When I run `disksked` randomly 
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct SCAN report
		Then 20 points are awarded

	Scenario: disksked correctly reports C_SCAN multiple times
		When I run `disksked` randomly 
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct C_SCAN report
		When I run `disksked` randomly 
		Then the stdout should contain the correct C_SCAN report
		Then 20 points are awarded

