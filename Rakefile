require 'bundler/setup'
require 'launchy'

def revision
  @revision ||= `git log -n 1 --format=%H`.chop
end

def branch
  @branch ||= ENV["WERCKER_GIT_BRANCH"] || `git symbolic-ref HEAD | sed -e 's!refs/heads/!!'`.chop
end

def book_name
  "great-h-book"
end

def types
  %W[epub pdf]
end

def base_url
  "http://great-h-book.eiel.info/"
end

def tmp_book
  "#{base_url}tmp/#{book_name}-#{revision}"
end

def pdf_url
  tmp_book + ".pdf"
end

def epub_url
  tmp_book + ".epub"
end

def latest_book
  "#{base_url}#{book_name}"
end

def latest_pdf
  "#{latest_book}.pdf?#{Time.now.to_i}"
end

def latest_epub
  "#{latest_book}.epub?#{Time.now.to_i}"
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

def object_name_base
  "tmp/#{book_name}-#{revision}"
end

task :copy do
  sh "cp -a src/* ."
end

task preprocess: :copy do
  sh "bundle exec bin/get_statics"
  sh "bundle exec bin/top-commit"
  sh "bundle exec review-preproc *.re --replace"
end

desc 'create book'
task create: [:'create:epub', :'create:pdf']

namespace :create do
  task epub: :preprocess do
    sh "bundle exec review-epubmaker config.yml"
  end

  task pdf: :preprocess do
    sh "bundle exec review-pdfmaker config.yml"
  end
end


task :clean do
  sh "rm -f *.re"
  sh "rm -f *.epub"
  sh "rm -rf *pdf"
  sh "rm -rf tmp"
end

desc 'deploy book'
task deploy: [:clean, :create] do
  types.each do |type|
    object_name = "#{object_name_base}.#{type}"
    object = bucket.objects[object_name]
    if result = object.exists? rescue false
      $stderr.puts "areaday objet: #{object_name}"
    else
      options = { acl: :public_read }
      case type
      when "epub"
        options[:content_type] = 'application/epub+zip'
      when "pdf"
        options[:content_type] = 'application/pdf'
      end
      object.write(open("#{book_name}.#{type}"), options)
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
      object_name = "#{object_name_base}.#{type}"
      object = bucket.objects[object_name]
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

namespace :open do
  task :pdf do
    Launchy.open(pdf_url)
  end
  task :epub do
    Launchy.open(epub_url)
  end
end

def twitter
  return @twitter if @twitter
  require 'twitter'
  @twitter = Twitter::REST::Client.new do |config|
    config.consumer_key = ENV["TWITTER_CONSUMER_KEY"]
    config.consumer_secret = ENV["TWITTER_CONSUMER_SECRET"]
    config.access_token = ENV["TWITTER_ACCESS_TOKEN"]
    config.access_token_secret = ENV["TWITTER_ACCESS_TOKEN_SECRET"]
  end
end

namespace :tweet do
  task :latest do
    twitter.update "すごい広島の本の最新版が更新されたよ。 #{latest_epub} #{latest_pdf} #すごい広島の本"
  end
  task :draft do
    twitter.update "#{branch}ブランチを元にしたすごい広島の本が生成されたよ。 #{epub_url} #{pdf_url} #すごい広島の本"
  end
end
