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
  maxlen = Dir["#{dir}/*.yab"].map(&:length).max
  total = Dir["#{dir}/*.yab"].length
  failed = 0
  puts "\nRunning #{total} tests in #{dir} with relative path to executable #{executable}:"
  cd dir do
    Dir["*.yab"].each do |file|
      sh (RUBY_PLATFORM=~/cygwin/ ? "cygstart --wait " : "") + executable + " " + file do |ok,res|
        print "Test #{file}".ljust(maxlen+8,".")
        if ok
          puts "\e[32mpassed.\e[0m"
        else
          puts "\e[31mFAILED !\e[0m"
          failed += 1
        end
      end
    end
  end
  printf "Total number of tests:  %4d\n",total
  printf "Number of failed tests: %4d\n",failed
  fail "Some tests failed !" if failed > 0
  fail "Did not find any tests !" if total == 0
  puts
end
