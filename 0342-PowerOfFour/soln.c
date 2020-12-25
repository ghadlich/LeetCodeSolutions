/* Copyright (c) 2019-2021 Grant Hadlich
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the Software), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
bool isPowerOfFour(int num){
    if (num < 0) return false;
    if (num == 1) return true;
    
    return ((num==(1<<2 ))||(num==(1<<4 ))||(num==(1<<6 ))||(num==(1<<8 ))||
	        (num==(1<<10))||(num==(1<<12))||(num==(1<<14))||(num==(1<<16))||
			(num==(1<<18))||(num==(1<<20))||(num==(1<<22))||(num==(1<<24))||
			(num==(1<<26))||(num==(1<<28))||(num==(1<<30)));
}
