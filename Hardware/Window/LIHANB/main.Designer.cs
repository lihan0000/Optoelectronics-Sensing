namespace LIHAN
{
    partial class main
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Series series2 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.Time = new System.Windows.Forms.TextBox();
            this.measure = new System.Windows.Forms.Button();
            this.spectrogram = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.cCDDATABindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.cCDDataSet = new LIHAN.CCDDataSet();
            this.Clear_DATA = new System.Windows.Forms.Button();
            this.View = new System.Windows.Forms.Button();
            this.cCD_DATATableAdapter = new LIHAN.CCDDataSetTableAdapters.CCD_DATATableAdapter();
            this.cCDDATABindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.spectrogram)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cCDDATABindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cCDDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cCDDATABindingSource1)).BeginInit();
            this.SuspendLayout();
            // 
            // Time
            // 
            this.Time.Location = new System.Drawing.Point(20, 100);
            this.Time.Multiline = true;
            this.Time.Name = "Time";
            this.Time.Size = new System.Drawing.Size(200, 50);
            this.Time.TabIndex = 1;
            this.Time.Text = "曝光时间";
            this.Time.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // measure
            // 
            this.measure.AllowDrop = true;
            this.measure.Location = new System.Drawing.Point(20, 180);
            this.measure.Name = "measure";
            this.measure.Size = new System.Drawing.Size(200, 50);
            this.measure.TabIndex = 2;
            this.measure.Text = "测量";
            this.measure.UseVisualStyleBackColor = true;
            this.measure.Click += new System.EventHandler(this.measure_Click);
            // 
            // spectrogram
            // 
            chartArea1.AxisX.Interval = 3648D;
            chartArea1.AxisX.Maximum = 3648D;
            chartArea1.AxisX.Minimum = 0D;
            chartArea1.AxisX.ScrollBar.BackColor = System.Drawing.Color.Black;
            chartArea1.AxisX.ScrollBar.ButtonColor = System.Drawing.Color.Red;
            chartArea1.AxisX.ScrollBar.Enabled = false;
            chartArea1.AxisX.ScrollBar.LineColor = System.Drawing.Color.Gray;
            chartArea1.AxisX.ScrollBar.Size = 20D;
            chartArea1.AxisX2.Enabled = System.Windows.Forms.DataVisualization.Charting.AxisEnabled.True;
            chartArea1.AxisX2.Interval = 100D;
            chartArea1.AxisX2.MajorGrid.Enabled = false;
            chartArea1.AxisX2.Maximum = 800D;
            chartArea1.AxisX2.Minimum = 200D;
            chartArea1.AxisX2.TitleAlignment = System.Drawing.StringAlignment.Near;
            chartArea1.AxisY.MajorGrid.Interval = 100D;
            chartArea1.AxisY.MajorTickMark.Interval = 100D;
            chartArea1.Name = "ChartArea1";
            this.spectrogram.ChartAreas.Add(chartArea1);
            this.spectrogram.Cursor = System.Windows.Forms.Cursors.Default;
            legend1.Name = "Legend1";
            this.spectrogram.Legends.Add(legend1);
            this.spectrogram.Location = new System.Drawing.Point(270, 20);
            this.spectrogram.Name = "spectrogram";
            series1.BackImageTransparentColor = System.Drawing.Color.White;
            series1.BackSecondaryColor = System.Drawing.Color.WhiteSmoke;
            series1.BorderColor = System.Drawing.Color.White;
            series1.BorderDashStyle = System.Windows.Forms.DataVisualization.Charting.ChartDashStyle.Dash;
            series1.ChartArea = "ChartArea1";
            series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Spline;
            series1.Color = System.Drawing.Color.Black;
            series1.Legend = "Legend1";
            series1.MarkerBorderColor = System.Drawing.Color.Black;
            series1.MarkerColor = System.Drawing.Color.Black;
            series1.MarkerStyle = System.Windows.Forms.DataVisualization.Charting.MarkerStyle.Star10;
            series1.Name = "CCD";
            series2.ChartArea = "ChartArea1";
            series2.Legend = "Legend1";
            series2.Name = "SPEC";
            series2.XAxisType = System.Windows.Forms.DataVisualization.Charting.AxisType.Secondary;
            this.spectrogram.Series.Add(series1);
            this.spectrogram.Series.Add(series2);
            this.spectrogram.Size = new System.Drawing.Size(1300, 800);
            this.spectrogram.TabIndex = 3;
            this.spectrogram.Text = "spectrogram";
            // 
            // cCDDATABindingSource
            // 
            this.cCDDATABindingSource.DataMember = "CCD_DATA";
            this.cCDDATABindingSource.DataSource = this.cCDDataSet;
            // 
            // cCDDataSet
            // 
            this.cCDDataSet.DataSetName = "CCDDataSet";
            this.cCDDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // Clear_DATA
            // 
            this.Clear_DATA.AllowDrop = true;
            this.Clear_DATA.Location = new System.Drawing.Point(20, 250);
            this.Clear_DATA.Name = "Clear_DATA";
            this.Clear_DATA.Size = new System.Drawing.Size(200, 50);
            this.Clear_DATA.TabIndex = 4;
            this.Clear_DATA.Text = "清空数据";
            this.Clear_DATA.UseVisualStyleBackColor = true;
            this.Clear_DATA.Click += new System.EventHandler(this.Clear_DATA_Click);
            // 
            // View
            // 
            this.View.AllowDrop = true;
            this.View.Location = new System.Drawing.Point(20, 20);
            this.View.Name = "View";
            this.View.Size = new System.Drawing.Size(200, 50);
            this.View.TabIndex = 5;
            this.View.Text = "显示图像";
            this.View.UseVisualStyleBackColor = true;
            // 
            // cCD_DATATableAdapter
            // 
            this.cCD_DATATableAdapter.ClearBeforeFill = true;
            // 
            // cCDDATABindingSource1
            // 
            this.cCDDATABindingSource1.DataMember = "CCD_DATA";
            // 
            // main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(14F, 28F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1774, 929);
            this.Controls.Add(this.View);
            this.Controls.Add(this.Clear_DATA);
            this.Controls.Add(this.spectrogram);
            this.Controls.Add(this.measure);
            this.Controls.Add(this.Time);
            this.Font = new System.Drawing.Font("楷体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "main";
            this.Text = "CCD";
            this.Load += new System.EventHandler(this.main_Load);
            ((System.ComponentModel.ISupportInitialize)(this.spectrogram)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cCDDATABindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cCDDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cCDDATABindingSource1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TextBox Time;
        private System.Windows.Forms.Button measure;
        private System.Windows.Forms.DataVisualization.Charting.Chart spectrogram;
        private System.Windows.Forms.Button Clear_DATA;
        private System.Windows.Forms.Button View;
        private CCDDataSet cCDDataSet;
        private System.Windows.Forms.BindingSource cCDDATABindingSource;
        private CCDDataSetTableAdapters.CCD_DATATableAdapter cCD_DATATableAdapter;
        private System.Windows.Forms.BindingSource cCDDATABindingSource1;
    }
}

