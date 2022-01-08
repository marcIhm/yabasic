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
  total = Dir["#{dir}/*.yab"].select {|x| !x.match(/library.*\.yab/)}.length
  failed = 0
  puts "\n\e[33mRunning #{total} tests in #{dir} with relative path to executable #{executable}:\e[0m"
  maxlen = Dir["#{dir}/*.yab"].select {|x| !x.match(/library.*\.yab/)}.map(&:length).max
  Dir["#{dir}/*.yab"].select {|x| !x.match(/library.*\.yab/)}.each do |fname|
    dir = File.dirname(fname)
    short = File.basename(fname)
    command = executable + " " + short
    expected_error = File.readlines(fname).select{ |l| l.start_with?("#expect#")}.map { |l| l[8..-1] }.join('')
    expected_error = nil if expected_error == ''
    if expected_error
      output = ""
      cd dir do
        [short,executable].each {|f|
          fail "File #{f} cannot be found" unless File.file?(f)
        }
        output = %x( #{command} 2>&1 )
      end
      result = (output == expected_error)
    else
      cd dir do
        [short,executable].each {|f|
          fail "File #{f} cannot be found" unless File.file?(f)
        }
        sh command do |ok,res|
          result = ok
          output = res
        end
      end
    end
    print "\e[35m" + "Test #{fname}".ljust(maxlen+8,".") + "\e[0m"
    if result
      puts "\e[32mpassed.\e[0m"
    else
      puts "\e[31mFAILED !\e[0m"
      puts output
      if expected_error
        puts "Was expecting:",expected_error
      end
      failed += 1
    end
    File.open(fname + '.log','w') {|f| f.write(output)}
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
  attr_accessor :paras

  def initialize fname
    @paras = []
    paras = File.read(fname).gsub(/^#.*$/,'').gsub(/\A(\s*\n)+/,'').split(/(?:^\s*\n)+/)
    all_versions = []
    paras.each { |para|
      p = News_para.new(para, fname)
      fail "Version #{p.version} has already been seen" if all_versions.include?(p.version)
      all_versions << p.version
      @paras << p
    }
    @version = @paras[0].version
  end

  def as_text
    @paras.map {|p| p.as_text}.join("\n\n")
  end
  
  def as_html indent
    @paras[0].as_html indent
  end

  def as_html_all indent
    @paras.map { |para| para.as_html indent }.join
  end
end

class News_para
  
  attr_reader :version
  
  def initialize para, fname
    lines = para.lines
    fail "Cannot parse version from line: '#{lines[0]}' in #{fname}" unless lines[0]=~/^Version (\d\.(?:\d+|\d+\.\d+))(?: \(([^,]+), (20\d+\d)\))?\s*$/;
    @version = $1
    @month_day = $2
    @year = $3
    @lines = []
    @text = para
    lines.drop(1).each do |l|
      case l
      ## To require a fixed number of spaces makes it easier to parse correctly
      when /^  - (.*?)\s*$/  
        @lines << $1.rstrip
      when /^    (\S.*?)\s*$/
        @lines[-1] += "\n" + l.rstrip
      else
        fail "Cannot parse non-version line: '#{l}'"
      end
    end
  end

  def as_text
    @text
  end
  
  def as_html indent
    fill = " " * indent
    fill + "<h4>Version #{@version}, #{@month_day}, #{@year}</h4>\n" +
      fill + "<ul>\n" +
      @lines.map {|l| fill + "  <li>#{l.gsub(/\n/,' ').gsub(/\s+/,' ').strip}</li>\n"}.join +
      fill + "</ul>\n"
  end
end
