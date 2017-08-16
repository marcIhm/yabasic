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
  puts "\n\e[33mRunning #{total} tests in #{dir} with relative path to executable #{executable}:\e[0m"
  cd dir do
    maxlen = Dir["*.yab"].map(&:length).max
    Dir["*.yab"].each do |fname|
      command = (RUBY_PLATFORM=~/cygwin/ ? "cygstart --wait " : "") + executable + " " + fname
      expected_error = File.readlines(fname).select{ |l| l.start_with?("#---")}.first
      if expected_error
        expected_error.chomp!
        puts "(Expecting error: '" + expected_error + "')"
        output = %x( #{command} 2>&1 )
        puts output
        result = !output.lines.select {|l| l.start_with?(expected_error[1..-1])}.first.nil?
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
  printf "\e[33mTotal number of tests:  %4d\e[0m\n",total
  if total==0
    fail "\e[31mDid not find any tests !\e[0m" if total == 0
  else
    if failed > 0
      printf "\e[31mNumber of failed tests: %4d\e[0m\n",failed
      fail "\e[31mSome tests failed !\e[0m" if failed > 0
    else
      printf "\e[32mNumber of failed tests: %4d\e[0m\n",failed
      printf "\e[32mAll tests passed.\e[0m\n",failed
    end
  end
  interactive_tests = Dir["#{dir}/interactive/*.yab"]
  if interactive_tests.length>0
    puts "\e[33mRemark: There are #{interactive_tests.length} interactive tests, that could be run if appropriate:\e[0m\n"
    interactive_tests.each {|t| puts "   \e[33m#{t}\e[0m\n"}
  end
end

class News
  
  attr_reader :version
  
  def initialize fname
    lines = File.readlines(fname)
    fail "Cannot parse first line of '#{fname}': #{lines[0]}" unless lines[0]=~/^Version (\d\.\d+\.\d+) \(([^,]+), (20\d+\d)\)\s*$/;
    @version = $1
    @month_day = $2
    @year = $3
    @lines = []
    lines.drop(1).each do |l|
      fail "Cannot parse line of '#{fname}': #{l}" unless l=~/^\s+-\s+(.*?)\s*$/
      @lines << $1
    end
  end
  
  def as_text
    "Version #{@version} (#{@month_day}, #{@year})\n" + @lines.map {|l| "  - #{l}\n"}.join
  end

  def as_html indent
    fill = " " * indent
    fill + "<h4>Version #{@version}, #{@month_day}, #{@year}</h4>\n" +
      fill + "<ul>\n" +
      @lines.map {|l| fill + "  <li>#{l}</li>\n"}.join +
      fill + "</ul>\n"
  end
end
