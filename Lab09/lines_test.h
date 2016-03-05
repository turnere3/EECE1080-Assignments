#ifndef LINES_TEST_H
#define LINES_TEST_H

#include <iostream>
#include <cxxtest/TestSuite.h>

#include "lines.cpp"

using namespace std;

// This requires CxxTest to be installed!
// For this CPPVideos example, navigate your terminal to CPPVideos and type:
// git submodule add https://github.com/CxxTest/cxxtest.git
// This will add the public CxxTest repository INSIDE the current repo.
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.


class LineDefaultSet : public CxxTest::TestSuite {
public:
  point_t a;
  point_t b;
  
  void setUp(){
    a.x_coord = 0.0;
    a.y_coord = 0.0;
    b.x_coord = 0.0;
    b.y_coord = 0.0;
  }
  
  void testLength0(){
    Line none;
    TS_ASSERT_DELTA(none.getLength(), 0.0, DDIFF);
  }
  
  void testLength1(){
    a.x_coord = 5.6;
    a.y_coord = 7.8;
    Line none(b,a);
    TS_ASSERT_DELTA(none.getLength(), sqrt(5.6*5.6 + 7.8*7.8), DDIFF);
  }
  
  void testLength2(){
    Line none;
    TS_ASSERT_DELTA(none.getLength(), 0.0, DDIFF);
    none.setPoints(a,b);
    TS_ASSERT_DELTA(none.getLength(), 0.0, DDIFF);
    a.x_coord = 1.0;
    b.x_coord = -5.0;
    none.setPoints(a,b);
    TS_ASSERT_DELTA(none.getLength(), 6.0, DDIFF);
  }
  
};

class LineGetPoints : public CxxTest::TestSuite {
public:
  point_t a;
  point_t b;
  
  void setUp(){
    a.x_coord = 0.0;
    a.y_coord = 0.0;
    b.x_coord = 0.0;
    b.y_coord = 0.0;
  }
  
  void testGetP1(){
    Line l;
    point_t f = l.getFirstPoint();
    point_t s = l.getSecondPoint();
    TS_ASSERT_DELTA(f.x_coord, a.x_coord, DDIFF);
    TS_ASSERT_DELTA(f.y_coord, a.y_coord, DDIFF);
    TS_ASSERT_DELTA(s.x_coord, a.x_coord, DDIFF);
    TS_ASSERT_DELTA(s.y_coord, a.y_coord, DDIFF);
  }
  
  void testGetP2(){
    a.x_coord = 56.0;
    a.y_coord = 66.0;
    Line l(a,b);
    point_t f = l.getFirstPoint();
    point_t s = l.getSecondPoint();
    TS_ASSERT_DELTA(f.x_coord, a.x_coord, DDIFF);
    TS_ASSERT_DELTA(f.y_coord, a.y_coord, DDIFF);
    TS_ASSERT_DELTA(s.x_coord, b.x_coord, DDIFF);
    TS_ASSERT_DELTA(s.y_coord, b.y_coord, DDIFF);
  }
  
};

class LineLength : public CxxTest::TestSuite {
public:
  point_t a;
  point_t b;
  
  void setUp(){
    a.x_coord = 0.0;
    a.y_coord = 0.0;
    b.x_coord = 0.0;
    b.y_coord = 0.0;
  }
  
  void testLength0(){
    Line none(a, b);
    TS_ASSERT_DELTA(none.getLength(), 0.0, DDIFF);
  }
  
  void testLength1(){
    a.x_coord = 1.0;
    Line l(a, b);
    TS_ASSERT_DELTA(l.getLength(), 1.0, DDIFF);
  }
  
  void testLength2(){
    a.y_coord = 1.0;
    Line l(a, b);
    TS_ASSERT_DELTA(l.getLength(), 1.0, DDIFF);
  }
  
  void testLength3(){
    b.x_coord = -10.0;
    Line l(a, b);
    TS_ASSERT_DELTA(l.getLength(), 10.0, DDIFF);
  }
  
  void testLength4(){
    b.y_coord = -10.0;
    Line l(a, b);
    TS_ASSERT_DELTA(l.getLength(), 10.0, DDIFF);
  }
  
  void testLength5(){
    a.x_coord = 3.0;
    b.y_coord = 4.0;
    Line l(a, b);
    TS_ASSERT_DELTA(l.getLength(), 5.0, DDIFF);
  }

};

class LineHorizontal : public CxxTest::TestSuite {
public:
  point_t a;
  point_t b;
  
  void setUp(){
    a.x_coord = 0.0;
    a.y_coord = 0.0;
    b.x_coord = 0.0;
    b.y_coord = 0.0;
  }

  void testH0(){
    Line l(a, b);
    TS_ASSERT(l.isHorizontal());
  }
  
  void testH1(){
    a.x_coord = 1.0;
    Line l(a, b);
    TS_ASSERT(l.isHorizontal());
  }
  
  void testH2(){
    b.x_coord = 1.0;
    Line l(a, b);
    TS_ASSERT(l.isHorizontal());
  }
  
  void testH3(){
    a.y_coord = 1.0;
    a.x_coord = 1.0;
    Line l(a, b);
    TS_ASSERT(!l.isHorizontal());
  }
  
  void testH4(){
    b.y_coord = 1.0;
    b.x_coord = 1.0;
    Line l(a, b);
    TS_ASSERT(!l.isHorizontal());
  }
};

class LineVertical : public CxxTest::TestSuite {
public:
  point_t a;
  point_t b;
  
  void setUp(){
    a.x_coord = 0.0;
    a.y_coord = 0.0;
    b.x_coord = 0.0;
    b.y_coord = 0.0;
  }

  void testV0(){
    Line l(a, b);
    TS_ASSERT(l.isVertical());
  }
  
  void testV1(){
    a.y_coord = 1.0;
    Line l(a, b);
    TS_ASSERT(l.isVertical());
  }
  
  void testV2(){
    b.y_coord = 1.0;
    Line l(a, b);
    TS_ASSERT(l.isVertical());
  }
  
  void testV3(){
    a.y_coord = 1.0;
    a.x_coord = 1.0;
    Line l(a, b);
    TS_ASSERT(!l.isVertical());
  }
  
  void testV4(){
    b.y_coord = 1.0;
    b.x_coord = 1.0;
    Line l(a, b);
    TS_ASSERT(!l.isVertical());
  }
};

class LineisParallel : public CxxTest::TestSuite {
public:
  point_t a;
  point_t b;
  
  void setUp(){
    a.x_coord = 0.0;
    a.y_coord = 0.0;
    b.x_coord = 0.0;
    b.y_coord = 0.0;
  }
  
  void testisParallel1(){
    // Two horizontal lines
    b.x_coord = 1.0;
    Line bottom(a,b);
    a.y_coord = 1.1;
    b.y_coord = 1.1;
    Line top(a,b);
    TS_ASSERT(bottom.isParallel(top));
  }
  
  void testisParallel2(){
    // Two steep lines
    b.x_coord = 1.0;
    b.y_coord = 10.0;
    Line bottom(a,b);
    a.y_coord = 1.1;
    b.y_coord = 11.1;
    Line top(a,b);
    TS_ASSERT(bottom.isParallel(top));
  }
  
  void testisParallel3(){
    // Two steep lines
    b.x_coord = 1.0;
    b.y_coord = -10.0;
    Line bottom(a,b);
    a.y_coord = -1.1;
    b.y_coord = -11.1;
    Line top(a,b);
    TS_ASSERT(bottom.isParallel(top));
  }
  
  void testisParallel4(){
    // Two vertical lines
    b.y_coord = 100.0;
    Line left(a,b);
    a.x_coord = 1.1;
    b.x_coord = 1.1;
    Line right(a,b);
    TS_ASSERT(left.isParallel(right));
  }
};

class LinePerpendicular : public CxxTest::TestSuite {
public:
  point_t a;
  point_t b;
  
  void setUp(){
    a.x_coord = 0.0;
    a.y_coord = 0.0;
    b.x_coord = 0.0;
    b.y_coord = 0.0;
  }
  
  void testPerp1(){
    // On axes
    b.x_coord = 1.0;
    Line x(a,b);
    a.y_coord = 1.1;
    b.x_coord = 0.0;
    b.y_coord = 0.0;
    Line y(a,b);
    TS_ASSERT(x.isPerpendicular(y));
  }
  
  void testisPerp2(){
    // On axes, but y is offset
    b.x_coord = 1.0;
    Line x(a,b);
    a.x_coord = 56.0;
    b.x_coord = 56.0;
    a.y_coord = 1.1;
    b.y_coord = 0.0;
    Line y(a,b);
    TS_ASSERT(x.isPerpendicular(y));
  }
  
  void testisPerp3(){
    // On axes, but y is offset
    b.x_coord = 1.0;
    Line x(a,b);
    a.x_coord = 54.0;
    b.x_coord = 54.0;
    a.y_coord = 1.1;
    b.y_coord = 0.0;
    Line y(a,b);
    TS_ASSERT(y.isPerpendicular(x));
  }
  
  void testisPerp4(){
    // An X
    a.x_coord = -10.0;
    a.y_coord = 10.0;
    b.x_coord = 0.0;
    b.y_coord = 0.0;
    Line dr(a,b);
    a.x_coord = 10.0;
    a.y_coord = 10.0;
    b.x_coord = 0.0;
    b.y_coord = 0.0;
    Line ur(a,b);
    TS_ASSERT(dr.isPerpendicular(ur));
  }
  
  void testisPerp5(){
    // A bent X
    a.x_coord = -11.0;
    a.y_coord = 10.0;
    b.x_coord = 0.0;
    b.y_coord = 0.0;
    Line dr(a,b);
    a.x_coord = 10.0;
    a.y_coord = 10.0;
    b.x_coord = 0.0;
    b.y_coord = 0.0;
    Line ur(a,b);
    TS_ASSERT(!dr.isPerpendicular(ur));
  }
  
};

class LineIntercept : public CxxTest::TestSuite {
public:
  point_t a;
  point_t b;
  
  void setUp(){
    a.x_coord = 0.0;
    a.y_coord = 0.0;
    b.x_coord = 0.0;
    b.y_coord = 0.0;
  }
  
  void testIntercept0(){
    // Horizontal on x axis
    b.x_coord = 1.0;
    Line l(a,b);
    TS_ASSERT_DELTA(l.getIntercept(), 0.0, DDIFF);
  }
  
  void testIntercept1(){
    // Horizontal at +5
    a.x_coord = 0.0;
    a.y_coord = 5.0;
    b.x_coord = 100.0;
    b.y_coord = 5.0;
    Line l(a,b);
    TS_ASSERT_DELTA(l.getIntercept(), 5.0, DDIFF);
  }
  
  void testIntercept2(){
    // 45 up from origin
    b.y_coord = 5.0;
    b.x_coord = 5.0;
    Line l(a,b);
    TS_ASSERT_DELTA(l.getIntercept(), 0.0, DDIFF);
  }
  
  void testIntercept3(){
    // 45 up from origin
    b.y_coord = 5.0;
    b.x_coord = 5.0;
    Line l(b,a);
    TS_ASSERT_DELTA(l.getIntercept(), 0.0, DDIFF);
  }
  
  void testIntercept4(){
    // 45 up from origin + 10
    a.x_coord = 1.0;
    a.y_coord = 10.0;
    b.x_coord = 2.0;
    b.y_coord = 11.0;
    Line l(a,b);
    TS_ASSERT_DELTA(l.getIntercept(), 9.0, DDIFF);
  }
  
  void testIntercept5(){
    // vertial (no intercept) verify 0.0
    b.y_coord = 5.0;
    Line l(b,a);
    TS_ASSERT_DELTA(l.getIntercept(), 0.0, DDIFF);
  }
};

class LineSlope : public CxxTest::TestSuite {
public:
  point_t a;
  point_t b;
  
  void setUp(){
    a.x_coord = 0.0;
    a.y_coord = 0.0;
    b.x_coord = 0.0;
    b.y_coord = 0.0;
  }
  
  void testSlope0(){
    // Horizontal on x axis
    b.x_coord = 1.0;
    Line l(a,b);
    TS_ASSERT_DELTA(l.getSlope(), 0.0, DDIFF);
  }
  
  void testSlope1(){
    // 45 through the origin
    b.x_coord = 5.0;
    b.y_coord = 5.0;
    Line l(a,b);
    TS_ASSERT_DELTA(l.getSlope(), 1.0, DDIFF);
  }
  
  void testSlope2(){
    // vertical
    b.y_coord = 5.0;
    Line l(a,b);
    TS_ASSERT_EQUALS(l.getSlope(), inf);
  }
  
  void testSlope3(){
    // -45 
    a.y_coord = 100.0;
    b.x_coord = 100.0;
    Line l(a,b);
    TS_ASSERT_DELTA(l.getSlope(), -1.0, DDIFF);
  }
  
  void testSlope4(){
    // -45 
    a.y_coord = 100.0;
    b.x_coord = 200.0;
    Line l(a,b);
    TS_ASSERT_DELTA(l.getSlope(), -1.0/2.0, DDIFF);
  }
  
};

class LineInfo : public CxxTest::TestSuite {
public:
  point_t a;
  point_t b;
  
  void setUp(){
    a.x_coord = 0.0;
    a.y_coord = 0.0;
    b.x_coord = 0.0;
    b.y_coord = 0.0;
  }

  void testInfo0(){
    Line l;
    TS_ASSERT_EQUALS(l.getLineInfo(), "0,0 0,0");
  }
  
  void testInfo1(){
    a.x_coord = 5.6;
    a.y_coord = 6.7;
    b.x_coord = 7.8;
    b.y_coord = 8.9;
    Line l(a,b);
    TS_ASSERT_EQUALS(l.getLineInfo(), "5.6,6.7 7.8,8.9");
  }
};

class LineDist : public CxxTest::TestSuite {
public:
  point_t a;
  point_t b;
  
  void setUp(){
    a.x_coord = 0.0;
    a.y_coord = 0.0;
    b.x_coord = 0.0;
    b.y_coord = 0.0;
  }
  
  void testDist0(){
    // Intersect
    a.x_coord = 1.0;
    b.x_coord = 1.0;
    Line lower(a,b);
    a.y_coord = 0.1;
    Line upper(a,b);
    TS_ASSERT_DELTA(lower.getDistance(upper), 0.0, DDIFF);
  }
  
  void testDist1(){
    // Parallel horizontally
    a.x_coord = 0.0;
    b.x_coord = 1.0;
    Line lower(a,b);
    a.y_coord = 0.1;
    b.y_coord = 0.1;
    Line upper(a,b);
    TS_ASSERT_DELTA(lower.getDistance(upper), 0.1, DDIFF);
  }
  
  void testDist2(){
    // Parallel vertically
    a.y_coord = 1.0;
    b.y_coord = 1.0;
    Line lower(a,b);
    a.x_coord = 0.1;
    b.x_coord = 0.1;
    Line upper(a,b);
    TS_ASSERT_DELTA(lower.getDistance(upper), 0.1, DDIFF);
  }
  
  void testDist3(){
    // 45
    b.x_coord = 1.0;
    b.y_coord = 1.0;
    Line lower(a,b);
    a.y_coord = 1.0;
    b.y_coord = 2.0;
    Line upper(a,b);
    TS_ASSERT_DELTA(lower.getDistance(upper), sqrt(2.0)/2, DDIFF);
  }
  
  void testDist4(){
    // -45
    a.x_coord = -1.0;
    a.y_coord = 1.0;
    Line lower(a,b);
    a.y_coord = 2.0;
    b.y_coord = 1.0;
    Line upper(a,b);
    TS_ASSERT_DELTA(lower.getDistance(upper), sqrt(2.0)/2, DDIFF);
  }
  
  void testDist5(){
    // -45
    a.x_coord = -1.0;
    a.y_coord = 1.0;
    Line lower(a,b);
    a.y_coord = 2.0;
    b.y_coord = 1.0;
    Line upper(a,b);
    TS_ASSERT_DELTA(upper.getDistance(lower), sqrt(2.0)/2, DDIFF);
  }
  
  void testDist6(){
    // -45
    a.x_coord = -1.0;
    a.y_coord = 1.0;
    Line lower(b,a);
    a.y_coord = 2.0;
    b.y_coord = 1.0;
    Line upper(b,a);
    TS_ASSERT_DELTA(lower.getDistance(upper), sqrt(2.0)/2, DDIFF);
  }
  
};
#endif
