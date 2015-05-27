def reFile(fn)
  File.open(fn,"r+") do |line|
    buffer = line.read.gsub(/( __attribute__\(\(availability\(macosx,(.)*=10.\d\)\)\))/, '/* \1 */');
    File.open(fn,"w"){|a| a.write(buffer)}
  end
end

reFile(ARGV)


# def hello(a)
#    puts a
# end

#  hello(ARGV)
