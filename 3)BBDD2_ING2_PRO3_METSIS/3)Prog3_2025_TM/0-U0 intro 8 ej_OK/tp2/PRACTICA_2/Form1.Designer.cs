namespace PRACTICA_2
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.btnRun1 = new System.Windows.Forms.Button();
            this.imageList1 = new System.Windows.Forms.ImageList(this.components);
            this.button2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnRun1
            // 
            this.btnRun1.BackColor = System.Drawing.SystemColors.Info;
            this.btnRun1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnRun1.Image = ((System.Drawing.Image)(resources.GetObject("btnRun1.Image")));
            this.btnRun1.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.btnRun1.Location = new System.Drawing.Point(254, 152);
            this.btnRun1.Name = "btnRun1";
            this.btnRun1.Size = new System.Drawing.Size(106, 62);
            this.btnRun1.TabIndex = 0;
            this.btnRun1.Text = "Run1";
            this.btnRun1.UseVisualStyleBackColor = false;
            this.btnRun1.Click += new System.EventHandler(this.btnRun1_Click);
            // 
            // imageList1
            // 
            this.imageList1.ColorDepth = System.Windows.Forms.ColorDepth.Depth8Bit;
            this.imageList1.ImageSize = new System.Drawing.Size(16, 16);
            this.imageList1.TransparentColor = System.Drawing.Color.Transparent;
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.SystemColors.Info;
            this.button2.Enabled = false;
            this.button2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.button2.Image = ((System.Drawing.Image)(resources.GetObject("button2.Image")));
            this.button2.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button2.Location = new System.Drawing.Point(492, 152);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(106, 62);
            this.button2.TabIndex = 1;
            this.button2.Text = "Run2";
            this.button2.UseVisualStyleBackColor = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.btnRun1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Click += new System.EventHandler(this.Form1_Click);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnRun1;
        private System.Windows.Forms.ImageList imageList1;
        private System.Windows.Forms.Button button2;
    }
}

