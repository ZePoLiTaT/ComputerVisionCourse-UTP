/* =====================================================================================
 *
 *       Filename:  POICorrespondence.cpp
 *
 *    Description:  
 *
 *        Version:  0.0.1
 *        Created:  May 29, 2013
 *       Compiler:  g++
 *
 *         Author:  Tatiana López G (ZePoLiTaT) 
 *  	     Mail:  tatiana@sirius.utp.edu.co
 *        Company:  Grupo de Investigación Sirius
 *
 * ===================================================================================*/

#include "POICorrespondence.h"


namespace poi
{

void POICorrespondence::findCorrespondences(const Mat &img1, vector<Point>& corners1, const Mat &img2,
		vector<Point>& corners2, multimap<Point, Point, PointCompare> &correspondences, float threshold,
		int WSize, int WShiftSize, IStrategyCompare *poiCompareMethod)
{
	mtype val;
	Point minpoint;
	Rect window;

	int WShiftHalfSize = floor(WShiftSize / 2);

	vector<Point>::iterator it1, it2;
	for (it1 = corners1.begin(); it1 != corners1.end(); ++it1)
	{
		for (it2 = corners2.begin(); it2 != corners2.end(); ++it2)
		{
			// if the point is not in the search window, do not take it into account
			if( it2->x <  (it1->x - WShiftHalfSize) || it2->x >  (it1->x + WShiftHalfSize) ||
				it2->y <  (it1->y - WShiftHalfSize) || it2->y >  (it1->y + WShiftHalfSize))
				continue;

			val = poiCompareMethod->getMeasure(img1, *it1, img2, *it2, WSize);


			if (poiCompareMethod->compare(val, threshold))
				correspondences.insert(pair<Point,Point>(*it1, *it2));
		}
	}
}

void POICorrespondence::plotCorrespondences(const Mat& img1, vector<Point>& corners1, const Mat& img2,
		multimap<Point, Point, PointCompare> &correspondences, Mat& dst)
{
	dst.create(max(img1.rows, img2.rows), img1.cols + img2.cols, img1.type());

	//ROI of bigger image pointing to first half
	Mat dstImg1 = dst(Rect(0, 0, img1.cols, img1.rows));
	//ROI of bigger image pointing to second half
	Mat dstImg2 = dst(Rect(img1.cols, 0, img2.cols, img2.rows));

	img1.copyTo(dstImg1);
	img2.copyTo(dstImg2);

	//Draw green lines
	Scalar colorL(0, 255, 0);

	int xP2;

	map<Point, Point>::iterator it;
	for (it = correspondences.begin(); it != correspondences.end(); ++it)
	{
		//Displace point in image2 since its located in the second half of the big image
		xP2 = it->second.x + img1.cols;
		line(dst, it->first, Point(xP2, it->second.y), colorL, 1, CV_AA);
	}
}

} /* namespace poisim */