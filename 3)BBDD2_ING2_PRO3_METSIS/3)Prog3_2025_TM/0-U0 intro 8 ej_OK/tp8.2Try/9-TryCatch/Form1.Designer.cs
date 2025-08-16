namespace _9_TryCatch
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
            this.lblIngreseNum = new System.Windows.Forms.Label();
            this.txtNumero = new System.Windows.Forms.TextBox();
            this.btnConvertir = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lblIngreseNum
            // 
            this.lblIngreseNum.AutoSize = true;
            this.lblIngreseNum.Location = new System.Drawing.Point(108, 44);
            this.lblIngreseNum.Name = "lblIngreseNum";
            this.lblIngreseNum.Size = new System.Drawing.Size(100, 13);
            this.lblIngreseNum.TabIndex = 0;
            this.lblIngreseNum.Text = "Ingresar un Numero";
            // 
            // txtNumero
            // 
            this.txtNumero.Location = new System.Drawing.Point(111, 73);
            this.txtNumero.Name = "txtNumero";
            this.txtNumero.Size = new System.Drawing.Size(100, 20);
            this.txtNumero.TabIndex = 1;
            // 
            // btnConvertir
            // 
            this.btnConvertir.Location = new System.Drawing.Point(120, 113);
            this.btnConvertir.Name = "btnConvertir";
            this.btnConvertir.Size = new System.Drawing.Size(75, 23);
            this.btnConvertir.TabIndex = 2;
            this.btnConvertir.Text = "Convertir";
            this.btnConvertir.UseVisualStyleBackColor = true;
            this.btnConvertir.Click += new System.EventHandler(this.btnConvertir_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(341, 176);
            this.Controls.Add(this.btnConvertir);
            this.Controls.Add(this.txtNumero);
            this.Controls.Add(this.lblIngreseNum);
            this.Name = "Form1";
            this.Text = "Manejo de Excepciones";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblIngreseNum;
        private System.Windows.Forms.TextBox txtNumero;
        private System.Windows.Forms.Button btnConvertir;
    }
}

