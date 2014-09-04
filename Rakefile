require 'bundler/setup'

def revision
  @revision ||= `git log -n 1 --format=%H`.chop
end

def branch
  @branch ||= `git symbolic-ref HEAD | sed -e 's!refs/heads/!!`.chop
end

def book_name
  "great-h-book"
end

def types
  %W[epub pdf]
end

def s3
  require 'aws/s3'
  @s3 ||= AWS::S3.new(
    access_key_id: ENV["AWS_ACCESS_KEY"],
    secret_access_key: ENV["AWS_SECRET_ACCESS_KEY"],
    region: ENV["AWS_REGION"],
  )
end

def bucket
  s3.buckets["great-h-book.eiel.info"]
end

def epub_object_name
  "tmp/#{book_name}-#{revision}"
end

desc 'create book'
task :create do
  sh "bundle exec review-epubmaker config.yml"
  sh "bundle exec review-pdfmaker config.yml"
end

desc 'deploy book'
task deploy: :create do
  types.each do |type|
    object = bucket.objects[epub_object_name]
    if result = object.exists? rescue false
      $stderr.puts "areaday objet: #{epub_object_name}"
    else
      object.write(open("#{book_name}.#{type}"), acl: :public_read)
    end
  end
end

namespace :deploy do
  desc 'deploy index.html'
  task :index do
    object = bucket.objects['index.html']
    object.write(open("index.html"), acl: :public_read)
  end

  desc 'deploy latest'
  task :latest do
    types.each do |type|
      object = bucket.objects[epub_object_name]
      name = "#{book_name}.#{type}"
      object.copy_to name
      bucket.objects[name].acl = :public_read
    end
  end
end

task :pry do
  require 'pry'
  Pry.start
end
