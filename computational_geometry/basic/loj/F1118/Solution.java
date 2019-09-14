// problem name: Incredible Molecules
// problem link: http://lightoj.com/volume_showproblem.php?problem=1118
// contest link: (?)
// time: (?)
// author: reyad

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;
 
public class Main {
    static Reader in = null;
    static PrintWriter out = null;
  
    static class Number implements Comparable<Number> {
        long a, b;
        Number(long a, long b) {
            this.a = a;
            this.b = b;
        }
        public int compareTo(Number n) {
            if(this.a * n.b > n.a * this.b) return 1;
            if(this.a * n.b < n.a * this.b) return -1;
            return 0;
        }
    }
 
    static class Point implements Comparable<Point> {
        long x, y;
        Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
        long dist2(Point p) {
            return (this.x - p.x) * (this.x - p.x) + (this.y - p.y) * (this.y - p.y);
        }
        double dist(Point p) {
            return Math.sqrt(dist2(p));
        }
        public int compareTo(Point p) {
            if(this.x == p.x) {
                if(this.y < p.y) return -1;
                if(this.y > p.y) return 1;
                return 0;
            }
            if(this.x < p.x) return -1;
            return 1;
        }
        public String toString() {
            return this.x + " " + this.y;
        }
    }
 
    static class Vec {
        long x, y;
        Vec(Point p1, Point p2) {
            this.x = p1.x - p2.x;
            this.y = p1.y - p2.y;
        }
        long cross(Vec v) {
            return this.x * v.y - v.x * this.y;
        }
        long dot(Vec v) {
            return this.x * v.x + this.y * v.y;
        }
    }
 
    static class Line {
        long a, b, c;
        Line(Point p1, Point p2) {
            this.a = p1.y - p2.y;
            this.b = p2.x - p1.x;
            this.c = p1.x * p2.y - p2.x * p1.y;
        }
        boolean isParallel(Line l) {
            return (this.a * l.b == l.a * this.b);
        }
        boolean isSame(Line l) {
            if(!isParallel(l)) return false;
            if(this.a != 0) return (this.c * l.a == l.c * this.a);
            return (this.b * l.c == l.b * this.c);
        }
        long evaluate(Point p) {
            return a * p.x + b * p.y + c;
        }
    }
 
    static class PointReal {
        double x, y;
        PointReal(double x, double y) {
            this.x = x;
            this.y = y;
        }
        PointReal mid(PointReal p) {
            return new PointReal((this.x + p.x)/2, (this.y + p.y)/2);
        }
        double dist(PointReal p) {
            return Math.sqrt((this.x - p.x) * (this.x - p.x) + (this.y - p.y) * (this.y - p.y));
        }
        boolean isSame(PointReal p) {
            return (Math.abs(this.x - p.x)) < 1e-6 && (Math.abs(this.y - p.y) < 1e-6);
        }
        PointReal rotate(double ang) {
            return new PointReal(this.x * Math.cos(ang) - this.y * Math.sin(ang), this.x * Math.sin(ang) + this.y * Math.cos(ang));
        }
    }
 
    static class VecReal {
        double x, y, r;
        VecReal(PointReal p1, PointReal p2) {
            this.x = p1.x - p2.x;
            this.y = p1.y - p2.y;
            this.r = Math.sqrt(this.x * this.x + this.y * this.y);
        }
        VecReal(double x, double y) {
            this.x = x;
            this.y = y;
            this.r = Math.sqrt(this.x * this.x + this.y * this.y);
        }
        VecReal reverse() {
            return new VecReal(this.x * -1, this.y * -1);
        }
        VecReal perpendicular() {
            return new VecReal(this.y, -this.x);
        }
        double dot(VecReal v) {
            return (this.x * v.x + this.y * v.y);
        }
        double cross(VecReal v) {
            return (this.x * v.y - v.x * this.y);
        }
        VecReal scale(double s) {
            return new VecReal(this.x * s, this.y * s);
        }
        PointReal translate(PointReal p) {
            return new PointReal(p.x + this.x, p.y + this.y);
        }
    }
 
    static class LineReal {
        double a, b, c;
        LineReal(PointReal p1, PointReal p2) {
            this.a = p1.y - p2.y;
            this.b = p2.x - p1.x;
            this.c = p1.x * p2.y - p2.x * p1.y;
        }
        LineReal(double a, double b, double c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
        boolean isParallel(LineReal l) {
            return Math.abs(this.a * l.b - l.a * this.b) < 1e-6;
        }
        LineReal getPerpendicularLineThrough(PointReal p) {
            return new LineReal(-this.b, this.a, this.b * p.x - this.a * p.y);
        }
        PointReal getIntersectionPoint(LineReal l) {
            if(isParallel(l)) return null;
            double d = this.a * l.b - l.a * this.b;
            return new PointReal((this.b * l.c - l.b * this.c)/d, (this.c * l.a - l.c * this.a)/d);
        }
    }
 
    static class Triangle {
        Point x, y, z;
        double a, b, c;
        double area = -1;
        double A = -1, B = -1, C = -1;
        Triangle(Point x, Point y, Point z) {
            this.x = x;
            this.y = y;
            this.z = z;
            this.a = y.dist(z);
            this.b = z.dist(x);
            this.c = x.dist(y);
        }
        Triangle(double a, double b, double c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
        static boolean isPossible(double a, double b, double c) {
            double m = Math.max(a, Math.max(b, c));
            if((a + b + c ) > (m+m)) return true;
            return false;
        }
        double getArea() {
            if(area + 1e-9 > 0) return area;
            area = 0.5 * (x.x * y.y + y.x * z.y + z.x * x.y) - (x.y * y.x + y.y * z.x + z.y * x.x);
            return area;
        }
        double getA() {
            if(A != -1) return A;
            A = Math.acos((b * b + c * c - a * a) / (2 * b * c));
            return A;
        }
        double getB() {
            if(B != -1) return B;
            B = Math.acos((c * c + a * a - b * b) / (2 * c * a));
            return B;
        }
        double getC() {
            if(C != -1) return C;
            C = Math.acos((a * a + b * b - c * c) / (2 * a * b));
            return C;
        }
    }
 
    static class Polygon {
        Point[] buf;
        int n, convex = -1;
        long area2 = Long.MAX_VALUE;
        double perimeter = -1, area = -1;
 
        Polygon(Point[] b) {
//            b is a anticlockwise ordered vertices of polygon
            this.n = b.length;
            this.buf = new Point[this.n+2];
            this.buf[this.n] = b[0];
            this.buf[this.n+1] = b[1];
            System.arraycopy(b, 0, this.buf, 0, this.n);
        }
        double getPerimeter() {
            if(perimeter != -1) return perimeter;
            perimeter = 0.0;
            for(int i=0; i<n; i++) perimeter += buf[i].dist(buf[i+1]);
            return  perimeter;
        }
        long getArea2() {
            if(area2 != Long.MAX_VALUE) return area2;
            area2 = 0;
            for(int i=0; i<n; i++) area2 += buf[i].x * buf[i+1].y - buf[i+1].x * buf[i].y;
            return area2;
        }
        double getArea() {
            if(area != -1) return area;
//            area = 0.0;
//            for(int i=0; i<n; i++) area += buf[i].x * buf[i+1].y - buf[i+1].x * buf[i].y;
            area = getArea2();
            area = Math.abs(area) * 0.5;
            return area;
        }
        boolean isConvex() {
            if(convex != -1) return (convex > 0);
            boolean flag = ccw(buf[0], buf[1], buf[2]);
            for(int i=1; i<n; i++) {
                if(ccw(buf[i], buf[i+1], buf[i+2]) != flag) {
                    convex = 0;
                    return false;
                }
            }
            convex = 1;
            return true;
        }
        static long triArea2(Point a, Point b, Point c) {
            return (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);
        }
        boolean inPolygon(Point p) {
            long a2 = Math.abs(getArea2());
            long a2t = 0;
            for (int i = 0; i < n; i++) a2t += Math.abs(triArea2(buf[i], p, buf[i + 1]));
            return (a2t == a2);
        }
    }
 
    static boolean ccw(Point a, Point b, Point c) {
        return ((new Vec(b, a)).cross(new Vec(c, a)) > 0);
    }
 
    static boolean inside(long x, long y, long v) {
        return (x <= v && v <= y);
    }
 
    static void solve() throws IOException, NullPointerException {
        try {
            int tc = in.nextInt();
            for(int cc=0; cc<tc; cc++) {
                Point o1 = new Point(in.nextInt(), in.nextInt());
                int r1 = in.nextInt();
                Point o2 = new Point(in.nextInt(), in.nextInt());
                int r2 = in.nextInt();
 
                double d = o1.dist(o2);
                if(r1+r2 < d+1e-6) {
                    out.println("Case " + (cc+1) + ": " + 0);
                    continue;
                }
                if(Math.max(r1, r2)+1e-6 > Math.min(r1, r2) + d) {
                    out.println("Case " + (cc+1) + ": " + (Math.PI * Math.min(r1, r2) * Math.min(r1, r2)));
                    continue;
                }
 
                double A = Math.acos((d * d + r1 * r1 - r2 * r2) / (2 * d * r1));
                double B = Math.acos((r2 * r2 + d * d - r1 * r1) / (2 * d * r2));
 
                double area1 = r1 * r1 * (A - 0.5 * Math.sin(2*A));
                double area2 = r2 * r2 * (B - 0.5 * Math.sin(2*B));
                out.println("Case " + (cc+1) +": " + (area1 + area2));
            }
        }
        catch(IOException e) {
            // expected
        }
//        catch(NullPointerException e) {
//            // expected
//        }
    }
 
    public static void main(String[] args) {
        try {
            in = new Reader();
            out = new PrintWriter(System.out, true);
            solve();
            out.close();
            in.close();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
    static class Reader {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        StringTokenizer tk = new StringTokenizer("");
        String s = null;
 
        String nextLine() throws IOException {
            while((s = br.readLine()) != null && s.length() == 0);
            return s;
        }
        String next() throws IOException {
            if(!tk.hasMoreTokens()) tk = new StringTokenizer(nextLine());
            return tk.nextToken();
        }
        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        long nextLong() throws IOException {
            return Long.parseLong(next());
        }
        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
        void close() throws  IOException {
            br.close();
            isr.close();
        }
    }
}