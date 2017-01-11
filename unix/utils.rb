def compare_semver one,two
  vers = [one, two].map do |x|
    md = x.match(/(\d+)\.(\d+)\.(\d+)/)
    fail "Argument '#{x}' does not contain a semantic version number" unless md
    [md[1],md[2],md[3]]
  end.transpose

  vers.inject(0) {|s,x| 2*s+(x[0]<=>x[1])} <=> 0
end

def cleanup glob
  Dir[glob].sort {|x,y| compare_semver x,y }[0..-2].each {|x| rm x}
end

def run_tests dir, executable
  total = Dir["#{dir}/*.yab"].length
  failed = 0
  puts "\nRunning #{total} tests in #{dir} with relative path to executable #{executable}:"
  cd dir do
    maxlen = Dir["*.yab"].map(&:length).max
    Dir["*.yab"].each do |fname|
      command = (RUBY_PLATFORM=~/cygwin/ ? "cygstart --wait " : "") + executable + " " + fname
      expected_error = File.readlines(fname).select{ |l| l.start_with?("#---Error")}.first
      result = 
      if expected_error
        result = !! %x( #{command} 2>&1 ).lines.select {|l| l.start_with?(expected_error[1..-1])}.first
      else
        sh command do |ok,res|
          result = ok
        end
      end
      print "\e[35m" + "Test #{fname}".ljust(maxlen+8,".") + "\e[0m"
      if result
        puts "\e[32mpassed.\e[0m"
      else
        puts "\e[31mFAILED !\e[0m"
        failed += 1
      end
    end
  end
  printf "Total number of tests:  %4d\n",total
  printf "Number of failed tests: %4d\n",failed
  fail "Some tests failed !" if failed > 0
  fail "Did not find any tests !" if total == 0
  puts
end
