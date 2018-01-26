@echo off
C:
cd \Users\444\hexo-demo\
echo Job start!
git add . && git commit -m "12µã±¸·Ý" && git push -u origin master && hexo clean && hexo g && hexo d && echo Job is done! && pause

