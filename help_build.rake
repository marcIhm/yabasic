
desc 'Describe building process'
task :h do
  within = false
  doc = File.open('../README.org').each do |line|
    within = true if line.include?('building sequence') && line.start_with?('*')
    print line if within
  end
end

desc 'Describe building process'
task :b => :h

