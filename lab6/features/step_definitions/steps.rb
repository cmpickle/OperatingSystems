require_relative 'tracks'

Before do
end

Given /^I run `disksked` randomly$/ do 
	if @dirs == nil then
		@dirs = ["tmp", "aruba"]
	end	
	r = Random.rand(0..$trackKeys.length-1)
	#puts "random value is #{r}"
	@randomTracks = $trackKeys[r]
	@randomReport = $trackTable[@randomTracks]
	@rpts = @randomReport.split("\n")
	@rptFCFS = @rpts[0]
	@rptSSTF = @rpts[1]
	@rptSCAN = @rpts[2]
	@rptCSCAN = @rpts[3]
	@cmd = "disksked " + @randomTracks
	puts "The random tracks are: #{@randomTracks}"
	step "I run `disksked #{@randomTracks}`"
end

Given /^the stdout should contain the correct (.*) report$/ do |report|
	if @dirs == nil then
		@dirs = ["tmp", "aruba"]
	end	
	case report
		when "FCFS"
			r = 0
		when "SSTF"
			r = 1
		when "SCAN"
			r = 2
		when "C_SCAN"
			r = 3
	end
	puts "The correct output for #{report} should be:\n\t#{@rpts[r]}"
	step "the output should contain \"" + @rpts[r] + "\""
end

Given /^the output should contain PWD$/ do 
	if @dirs == nil then
		@dirs = ["tmp", "aruba"]
	end	
	#puts ENV['PWD']
	#puts ENV['HOME']
	#puts @dirs.join("/")
	#step "the output should match /" + Regexp.escape(ENV['PWD']) + "/"
	step "the output should contain \"" +  ENV['PWD'] + "/" + @dirs.join("/") + "\""
end

Given /^the output should contain HOME$/ do 
	puts "The home directory is #{ENV['HOME']}"
	#puts @dirs.join("/")
	#step "the output should match /" + Regexp.escape(ENV['HOME']) + "$/"
	step "the output should contain \"" +  ENV['HOME'] + "\n" + "\""
	#step "the output should not contain \"" +  ENV['HOME'] + "/" + "\""
end

Given /^the output should contain the host name$/ do
	#puts "The Host Name here is " + ENV['PWD']
	#step "the output should match /" + Regexp.escape(ENV['PWD']) + "/"
	#step "the output should contain \"" + #{str} + " " + ENV['HOSTNAME'] + "\""
	#step "the output should contain \"icarus\""
	@host = `hostname`
	puts "The Host Name here is " + @host 
	step "the output should contain \"" + @host + "\""
end

Given /^the output should contain the pid\/ppid$/ do
	@mypid = $?.pid
	@myppid = Process.pid
	puts "The pid is " + "#{@mypid}" + " and the PPID is " + "#{@myppid}"
	step "the output should contain \"" + "#{@mypid}/#{@myppid}" + "\""
end

Given /^there is only one (.*) running$/ do |pgm|
	@cnt = `ps --no-header -C #{pgm} | wc -l`
	if @cnt != "1" 
		@psout = `ps -C #{pgm}`
		raise "There are more than one #{pgm} programs running.\n#{@psout}"
	end
end

Given /^(.*) points are awarded/ do |points|
	#puts "#{points} points are now awarded!!!"
	$total_points += points.to_i
end

Given /^dot is replaced with PWD\/(.*)$/ do |outputfile|
	step "the output should contain \"copy #{outputfile} #{ENV['PWD']}\/#{File.join(@dirs)}\/#{outputfile}\""
end

Given /^timeout is increased by (.*) seconds$/ do |seconds|
	if @aruba_timeout_seconds  
		@aruba_timeout_seconds += seconds.to_i
	else
		puts "aruba_timeout_seconds is NIL!"
	end
end

Given /^timeout is decreased by (.*) seconds$/ do |seconds|
	if @aruba_timeout_seconds
		@aruba_timeout_seconds -= seconds.to_i
	else
		puts "aruba_timeout_seconds is NIL!"
	end
end

