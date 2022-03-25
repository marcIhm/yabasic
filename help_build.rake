
desc 'Describe building process'
task :h do
  within = false
  doc = File.open(%x{git rev-parse --show-toplevel}.chomp + '/README.org').each do |line|
    within = true if line.include?('Notes for the maintainer') && line.start_with?('*')
    print line if within
  end
end

desc 'Describe building process'
task :b => :h

