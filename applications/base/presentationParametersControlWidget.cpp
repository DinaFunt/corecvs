/**
 * \file presentationParametersControlWidget.cpp
 * \attention This file is automatically generated and should not be in general modified manually
 *
 * \date MMM DD, 20YY
 * \author autoGenerator
 */

#include "presentationParametersControlWidget.h"
#include "ui_presentationParametersControlWidget.h"
#include "qSettingsGetter.h"
#include "qSettingsSetter.h"


PresentationParametersControlWidget::PresentationParametersControlWidget(QWidget *parent, bool _autoInit, QString _rootPath)
    : ParametersControlWidgetBase(parent)
    , mUi(new Ui::PresentationParametersControlWidget)
    , autoInit(_autoInit)
    , rootPath(_rootPath)
{
    mUi->setupUi(this);

    QObject::connect(mUi->leftFrameButton, SIGNAL(clicked(bool)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->rightFrameButton, SIGNAL(clicked(bool)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->stereoComboBox, SIGNAL(currentIndexChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->flowComboBox, SIGNAL(currentIndexChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->outputComboBox, SIGNAL(currentIndexChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->showClustersCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->showHistogramCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->autoUpdateHistogramCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->showAreaOfInterestCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->produce3DCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->produce6DCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
    QObject::connect(mUi->dump3DCheckBox, SIGNAL(stateChanged(int)), this, SIGNAL(paramsChanged()));
}

PresentationParametersControlWidget::~PresentationParametersControlWidget()
{

    delete mUi;
}

void PresentationParametersControlWidget::loadParamWidget(WidgetLoader &loader)
{
    PresentationParameters *params = createParameters();
    loader.loadParameters(*params, rootPath);
    setParameters(*params);
    delete params;
}

void PresentationParametersControlWidget::saveParamWidget(WidgetSaver  &saver)
{
    PresentationParameters *params = createParameters();
    saver.saveParameters(*params, rootPath);
    delete params;
}


PresentationParameters *PresentationParametersControlWidget::createParameters() const
{

    /**
     * We should think of returning parameters by value or saving them in a preallocated place
     **/


    PresentationParameters *result = new PresentationParameters(
          mUi->leftFrameButton->isChecked()
        , mUi->rightFrameButton->isChecked()
        , static_cast<StereoStyle::StereoStyle>(mUi->stereoComboBox->currentIndex())
        , static_cast<FlowStyle::FlowStyle>(mUi->flowComboBox->currentIndex())
        , static_cast<OutputStyle::OutputStyle>(mUi->outputComboBox->currentIndex())
        , mUi->showClustersCheckBox->isChecked()
        , mUi->showHistogramCheckBox->isChecked()
        , mUi->autoUpdateHistogramCheckBox->isChecked()
        , mUi->showAreaOfInterestCheckBox->isChecked()
        , mUi->produce3DCheckBox->isChecked()
        , mUi->produce6DCheckBox->isChecked()
        , mUi->dump3DCheckBox->isChecked()
    );
    return result;
}

void PresentationParametersControlWidget::setParameters(const PresentationParameters &input)
{
    // Block signals to send them all at once
    bool wasBlocked = blockSignals(true);
    mUi->leftFrameButton->setChecked(input.leftFrame());
    mUi->rightFrameButton->setChecked(input.rightFrame());
    mUi->stereoComboBox->setCurrentIndex(input.stereo());
    mUi->flowComboBox->setCurrentIndex(input.flow());
    mUi->outputComboBox->setCurrentIndex(input.output());
    mUi->showClustersCheckBox->setChecked(input.showClusters());
    mUi->showHistogramCheckBox->setChecked(input.showHistogram());
    mUi->autoUpdateHistogramCheckBox->setChecked(input.autoUpdateHistogram());
    mUi->showAreaOfInterestCheckBox->setChecked(input.showAreaOfInterest());
    mUi->produce3DCheckBox->setChecked(input.produce3D());
    mUi->produce6DCheckBox->setChecked(input.produce6D());
    mUi->dump3DCheckBox->setChecked(input.dump3D());
    blockSignals(wasBlocked);
    emit paramsChanged();
}

void PresentationParametersControlWidget::setParametersVirtual(void *input)
{
    // Modify widget parameters from outside
    PresentationParameters *inputCasted = static_cast<PresentationParameters *>(input);
    setParameters(*inputCasted);
}