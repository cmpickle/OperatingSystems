Feature: Source files must be present, compilable and output correct information

	Scenario: required files must have been uploaded to Canvas
		#
		# STUDENTS: This cannot be tested until you SUBMIT TO CANVAS!!!"
		#  (You get the points here for free)
		#
		When a file named "../../xv6-public/syscall.c" should exist
		And a file named "../../xv6-public/syscall.h" should exist
		And a file named "../../xv6-public/sysproc.c" should exist
		And a file named "../../xv6-public/trap.c" should exist
		And a file named "../../xv6-public/user.h" should exist
		And a file named "../../xv6-public/usys.S" should exist
		Then 50 points are awarded

	Scenario: xv6 must be compilable with no errors
		When I run `bash -c 'cd ../../xv6-public; make clean; make'` 
		Then a file named "../../xv6-public/kernel" should exist
		Then a file named "../../xv6-public/fs.img" should exist
		Then a file named "../../xv6-public/xv6.img" should exist
		Then 50 points are awarded
		Then I run `killall qemu-system-i386`

	Scenario: xv6 under qemu should issue the appropriate prompt
		When I run `qemu-system-i386 -nographic -hdb ../../xv6-public/fs.img ../../xv6-public/xv6.img -smp 2 -m 512` interactively
		Then the output should contain "$"
		Then 50 points are awarded
		Then I run `killall qemu-system-i386`
		
	Scenario: peep should return success
		When I run `qemu-system-i386 -nographic -hdb ../../xv6-public/fs.img ../../xv6-public/xv6.img -smp 2 -m 512` interactively
		# qemu eats the first character typed for some reason
		And I type " "
		And I type "peep 50"
		Then the output should contain "Success"
		Then 50 points are awarded
		Then I run `killall qemu-system-i386`
		
