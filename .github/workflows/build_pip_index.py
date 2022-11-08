
import sys, os

REPO_URL = sys.argv[1]
TAG = sys.argv[2]
DIST = sys.argv[3]

page = """<!DOCTYPE html>
<html>
  <body>
    <a href="test/">test</a><br/>
  </body>
</html>
"""

if not os.path.exists(DIST):
    os.mkdir(DIST)

with open(DIST + "/index.html", "w") as f:
    f.write(page)
