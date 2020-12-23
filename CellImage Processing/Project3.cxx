#include "itkTIFFImageIO.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkThresholdImageFilter.h"
#include "itkNormalizeImageFilter.h"
#include "itkCastImageFilter.h"
#include "itkOtsuMultipleThresholdsImageFilter.h"
#include "itkOtsuMultipleThresholdsCalculator.h"
#include "itkRescaleIntensityImageFilter.h"

#include "itkMorphologicalWatershedFromMarkersImageFilter.h"
#include "itkScalarToRGBColormapImageFilter.h"
#include "itkScalarToRGBPixelFunctor.h"
#include "itkStatisticsImageFilter.h"
#include "itkSmoothingRecursiveGaussianImageFilter.h"
#include "itkMaskNegatedImageFilter.h"
//#include "itkLabelOverlayImageFilter.h"
#include "itkGrayscaleConnectedOpeningImageFilter.h"
#include "itkThresholdImageFilter.h"
#include "itkHMinimaImageFilter.h"
#include "itkLabelMapOverlayImageFilter.h"
#include "itkInvertIntensityImageFilter.h"
#include "itkWatershedImageFilter.h"
#include "itkValuedRegionalMinimaImageFilter.h"

#include "itkCurvatureFlowImageFilter.h"

#include "itkConnectedThresholdImageFilter.h"

#include "itkHConcaveImageFilter.h"

//#include "itkLabelMap.h"
//#include "itkLabelImageToLabelMapFilter.h"
//#include "itkWatershedImageFilter.h"
int main(int argc, char*argv[]){
    const unsigned int Dimention = 2;
    typedef unsigned char PixelType;
   // const unsigned int ContrastGlobal;
    
    typedef itk:: Image<PixelType, Dimention> ImageType;
    typedef itk:: Image<double, Dimention> InternalImageType;
    typedef itk::CastImageFilter<ImageType, InternalImageType> CastImageCharToDoubleType;
    typedef itk::CastImageFilter<InternalImageType, ImageType> CastImageDoubleToCharType;

    typedef itk::RGBPixel<unsigned char> RGBPixelType;
    using RGBImageType = itk::Image<RGBPixelType,2>;
    
    using LabeledImageType = itk::Image<unsigned char,Dimention>;

    
    //typename MaskImageType::Pointer outputmask =
    
    
    typedef itk::ImageFileReader<ImageType> ReaderType;
    typedef itk::ImageFileWriter<RGBImageType> WriterType;
    //typedef itk::ImageFileReader<InternalImageType> SampleReaderType;

   // typedef itk::ImageFileReader<MaskImageType> MaskReaderType;
    
    ReaderType::Pointer reader = ReaderType::New();
    WriterType::Pointer writer = WriterType::New();
    //SampleReaderType::Pointer samplereader = SampleReaderType::New();
    CastImageCharToDoubleType:: Pointer castImageCtD = CastImageCharToDoubleType::New();
    CastImageDoubleToCharType:: Pointer castImageDtC = CastImageDoubleToCharType::New();

   
    typedef itk::TIFFImageIO  ImageIOType;
    ImageIOType::Pointer tiffIO = ImageIOType::New();
    
    //unsigned char lowerThreshold = ;
    //unsigned char upperThreshold = ;
    
    using FilterType = itk::ThresholdImageFilter<ImageType>;
    FilterType:: Pointer filter = FilterType::New();
    
    using NormalizeType = itk::NormalizeImageFilter<ImageType,ImageType>;
    NormalizeType::Pointer normalizefilter = NormalizeType::New();
    
    using OtsuMultiThresholdType = itk::OtsuMultipleThresholdsImageFilter<InternalImageType, InternalImageType>;
    OtsuMultiThresholdType:: Pointer otsumultifilter = OtsuMultiThresholdType::New();
    
    using SmoothingType = itk::SmoothingRecursiveGaussianImageFilter<InternalImageType,InternalImageType>;
    SmoothingType::Pointer smoothingfilter = SmoothingType::New();
    
    using RescaleType = itk::RescaleIntensityImageFilter<InternalImageType,InternalImageType>;
    RescaleType::Pointer rescaler = RescaleType::New();
    
    using WatershedFilterType = itk::MorphologicalWatershedFromMarkersImageFilter<InternalImageType, InternalImageType>;
    WatershedFilterType::Pointer watershed = WatershedFilterType::New();
    
    using RGBFliterType = itk::ScalarToRGBColormapImageFilter<LabeledImageType, RGBImageType>;
    RGBFliterType::Pointer colormapFilter = RGBFliterType::New();
    
    using StatisticType = itk::StatisticsImageFilter<InternalImageType>;
    StatisticType::Pointer statisticFilter = StatisticType::New();
    
    using MaskNegetedType = itk::MaskNegatedImageFilter<InternalImageType, InternalImageType>;
    MaskNegetedType::Pointer masknegetedFilter = MaskNegetedType::New();
    
    using GrayOpeningType = itk::GrayscaleConnectedOpeningImageFilter<InternalImageType, InternalImageType>;
    GrayOpeningType::Pointer grayscaleopeningfilter = GrayOpeningType::New();
    
    using ThresholdImageType = itk::ThresholdImageFilter<InternalImageType>;
    ThresholdImageType:: Pointer thresholdImagefilter = ThresholdImageType::New();
    
   // using LabelOverLayType = itk::LabelOverlayImageFilter<InternalImageType, LabeledImageType, InternalImageType>;
    //LabeledImageType::Pointer labeloverlayfilter = LabelOverLayType::New();
    
    using MinimaImageType = itk::HMinimaImageFilter<InternalImageType, InternalImageType>;
    MinimaImageType::Pointer minimainmagefilter = MinimaImageType::New();
    
    using InvertIntensityImageType = itk::InvertIntensityImageFilter<InternalImageType>;
    InvertIntensityImageType::Pointer invertintensityfilter = InvertIntensityImageType::New();
    
    using WatershedSeparateType = itk::WatershedImageFilter<InternalImageType>;
    WatershedSeparateType::Pointer watershedfilter = WatershedSeparateType::New();
    
    using ValuedRegionalMinimaType = itk::ValuedRegionalMinimaImageFilter<InternalImageType,InternalImageType>;
    ValuedRegionalMinimaType::Pointer valuedregionalfilter = ValuedRegionalMinimaType::New();
    
    using ConnectedThresholdType = itk::ConnectedThresholdImageFilter<InternalImageType, InternalImageType>;
    ConnectedThresholdType::Pointer connectedthresholdfilter = ConnectedThresholdType::New();
    
    using CurvatureFlowType = itk::CurvatureFlowImageFilter<InternalImageType, InternalImageType>;
    CurvatureFlowType::Pointer curvaturefilter = CurvatureFlowType::New();
    
    using ConcaveImageType = itk::HConcaveImageFilter<InternalImageType, InternalImageType>;
    ConcaveImageType::Pointer concavefilter = ConcaveImageType::New();
   // using LabelObjectType = itk::LabelObject<LabeledImageType, Dimention>;
    
    // using LabelMapType = itk::LabelMap<LabelObjectType>;
    
   // using ConverterType = itk::LabelImageToLabelMapFilter<InternalImageType,LabelMapType>;
   // ConverterType::Pointer converter = ConverterType::New();
    
    
    

    const char* inputImage = argv[1];
    const char* outputImage = argv[2];
    reader->SetImageIO(tiffIO);
    reader->SetFileName(inputImage);
    reader->Update();
    //reader location
    castImageCtD->SetInput(reader->GetOutput());
    castImageCtD->Update();
    
    otsumultifilter->SetInput(castImageCtD->GetOutput());
    otsumultifilter->SetNumberOfHistogramBins(255);
    otsumultifilter->SetNumberOfThresholds(2);
    otsumultifilter->SetLabelOffset(1);
    
    
//    statisticFilter->SetInput(otsumultifilter->GetOutput());
//    statisticFilter->GetMinimum();
    
    
    //smoothingfilter->SetInput(castImageCtD->GetOutput());
    //smoothingfilter->SetSigma(0.000000000000000001);
    //smoothingfilter->Update();
   // smoothingfilter->SetTimeStep(0.00842175);
    

    
    
    
    //smoothingfilter->SetSigma(1);


    
   // smoothingfilter->NormalizeAcrossScaleOn();

    
    //smoothingfilter->SetNumberOfIterations(20);
    
    //smoothingfilter->SetSigma(0.000000000000001);
    //smoothingfilter->NormalizeAcrossScaleOn();
    //smoothingfilter->SetReferenceCount(100000000);
   // minimainmagefilter->SetInput(smoothingfilter->GetOutput());
    //minimainmagefilter->SetHeight(30);
    //minimainmagefilter->SetFullyConnected(true);
    //minimainmagefilter->Update();
    
    valuedregionalfilter->SetInput(castImageCtD->GetOutput());
    
    

    
    

    
    
    rescaler->SetInput(otsumultifilter->GetOutput());//double
    rescaler->SetOutputMinimum(0);
    rescaler->SetOutputMaximum(255);
    rescaler->Update();
    thresholdImagefilter->SetInput(rescaler->GetOutput());
    thresholdImagefilter->SetOutsideValue(255);//nu mask
    thresholdImagefilter->ThresholdAbove(50);//nu mask
   // thresholdImagefilter->ThresholdBelow(200);//only this is nu mask

  //  thresholdImagefilter->SetLower(otsumultifilter->GetReturnBinMidpoint());
   // thresholdImagefilter->SetUpper(255);
    thresholdImagefilter->Update();
    
    curvaturefilter->SetInput(castImageCtD->GetOutput());
   // curvaturefilter->SetTimeStep(0);
    //curvaturefilter->SetNumberOfIterations(1);
    concavefilter->SetInput(curvaturefilter->GetOutput());
    concavefilter->SetHeight(85);
    concavefilter->SetFullyConnected(false);
    
    
    connectedthresholdfilter->SetInput(curvaturefilter->GetOutput());
    connectedthresholdfilter->SetUpper(10);
    connectedthresholdfilter->SetLower(100);
    connectedthresholdfilter->Update();
    
    invertintensityfilter->SetInput(concavefilter->GetOutput());
    invertintensityfilter->SetMaximum(255);

    invertintensityfilter->Update();
    
    //watershedfilter->SetInput(thresholdImagefilter->GetOutput());
    
    
    
    
    //grayscaleopeningfilter->SetInput(rescaler->GetOutput());
    //grayscaleopeningfilter->FullyConnectedOff();
   // grayscaleopeningfilter->SetSeed();
   // grayscaleopeningfilter->Update();
    
    watershed->SetInput(thresholdImagefilter->GetOutput());//double
    watershed->SetMarkerImage(invertintensityfilter->GetOutput());
    watershed->MarkWatershedLineOn();
    watershed->FullyConnectedOff();
    
    //watershed->SetInput2(minimainmagefilter->GetOutput());
    

   // watershed->FullyConnectedOn();
  //  watershed->SetFullyConnected(false);
   // watershed->SetMarkWatershedLine(true);
    
    
   // watershed->MarkWatershedLineOn();
   // watershed->SetInput(0, rescaler->GetOutput());
    watershed->Update();
     castImageDtC->SetInput(watershed->GetOutput());
     castImageDtC->Update();

    colormapFilter->SetInput(castImageDtC->GetOutput());
    colormapFilter->SetColormap(RGBFliterType::ColormapEnumType::Jet);

    colormapFilter->Update();
    


//    filter->SetInput(reader->GetOutput());
//    filter->ThresholdOutside(lowerThreshold, upperThreshold);
//    filter->SetOutsideValue(0);
    //normalizefilter->SetInput(reader->GetOutput());
    
    
    //filter->Update();
    
    writer->SetImageIO(tiffIO);
    writer->SetFileName(outputImage);//writer location
    

    
    writer->SetInput(colormapFilter->GetOutput());
    
    
    
        writer->Update();

    
    
    
}

